/*
 * Copyright (c) 2016, Ari Suutari <ari@stonepile.fi>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. The name of the author may not be used to endorse or promote
 *     products derived from this software without specific prior written
 *     permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Loosely Based on simple LwIP dhcp server by Mark Lakata, posted
 * on lwip mailing list.
 * https://lists.gnu.org/archive/html/lwip-users/2012-12/msg00016.html
 */

#include <stdio.h>
#include <string.h>

#include "lwip/api.h"
#include "lwip/inet.h"
#include "lwip/sockets.h"
#include "lwip/tcpip.h"
#include "lwip/ip_addr.h"
#include "lwip/udp.h"
#include "lwip/ip.h"
#include "netif/etharp.h"
#include "lwip/prot/dhcp.h"
#include "flash_api.h"
#include "mac.h"
#include "fhost_cntrl.h"

/*
 * DHCP message types.
 */
#define DHCPDISCOVER  1
#define DHCPOFFER     2
#define DHCPREQUEST   3
#define DHCPDECLINE   4
#define DHCPACK       5
#define DHCPNAK       6
#define DHCPRELEASE   7
#define DHCPINFORM    8

/*
 * DHCP option codes that are used.
 */
#define OPT_NETMASK     1
#define OPT_REQ_IP      50
#define OPT_LEASE_TIME  51
#define OPT_MSGTYPE     53
#define OPT_SERVERID    54
#define OPT_RENEW_TIME  58
#define OPT_REBIND_TIME 59
#define OPT_END         255


#define LWIP_IANA_PORT_DHCP_CLIENT 68
#define LWIP_IANA_PORT_DHCP_SERVER 67

static struct udp_pcb* dhcpPcb;
typedef struct
{
  struct eth_addr mac;
  ip4_addr_t ip;
} Lease;
static uint16_t lease_time  = 24 * 60;
static uint32_t dhcps_start = 10;
//static uint32_t dhcps_end   = 20;

static uint8_t dhcps_offered = 0;

#define MAX_LEASES 10
static Lease leases[MAX_LEASES];
static const uint8_t freeMac[6] = { 0, 0, 0, 0, 0, 0 };

static int allocateAddr(struct eth_addr* mac, ip4_addr_t* ip)
{
  // search for existing
  for (int i = 0; i < MAX_LEASES; i++) {
    if (memcmp(mac->addr, leases[i].mac.addr, 6) == 0) {

      ip4_addr_copy(*ip, leases[i].ip);
      return 0;
    }
  }
  // create new one
  for (int i = 0; i < MAX_LEASES; i++) {
    if (memcmp(leases[i].mac.addr, freeMac, 6) == 0) {

      memcpy(leases[i].mac.addr, mac->addr, 6);
      ip4_addr_copy(*ip, leases[i].ip);
      dhcps_offered++;
      return 0;
    }
  }
  return -1;
}

static uint8_t getOption(uint8_t* optPtr)
{
  return optPtr[0];
}

static uint8_t getOptionLen(uint8_t* optPtr)
{
  return optPtr[1];
}

static uint8_t* getOptionData(uint8_t* optPtr)
{
  return optPtr + 2;
}

static void nextOption(uint8_t** optPtrPtr)
{
  uint8_t* optPtr  =*optPtrPtr;

  *optPtrPtr = optPtr + getOptionLen(optPtr) + 2;
}

static void addOptionTime(uint8_t** optPtrPtr, uint8_t opt, uint32_t t)
{
  uint8_t* optPtr = *optPtrPtr;

  *optPtr++ = opt;
  *optPtr++ = 4;

  *optPtr++ = (t / (256*256*256));
  t %= 256*256*256;

  *optPtr++ = (t / (256*256));
  t %= 256*256;

  *optPtr++ = (t / (256));
  t %= 256;

  *optPtr++ = t;

  *optPtrPtr = optPtr;
}

static void addOptionIP(uint8_t** optPtrPtr, uint8_t opt, const ip4_addr_t* ip)
{
  uint8_t* optPtr = *optPtrPtr;

  *optPtr++ = opt;
  *optPtr++ = 4;
  memcpy(optPtr, &ip4_addr_get_u32(ip), 4);
  optPtr += 4;

  *optPtrPtr = optPtr;
}

static void addOptionByte(uint8_t** optPtrPtr, uint8_t opt, uint8_t val)
{
  uint8_t* optPtr = *optPtrPtr;

  *optPtr++ = opt;
  *optPtr++ = 1;
  *optPtr++ = val;
  *optPtrPtr = optPtr;
}

static struct pbuf* newResp(struct pbuf* p)
{
    struct pbuf* rp;

    rp = pbuf_alloc(PBUF_TRANSPORT, sizeof(struct dhcp_msg), PBUF_RAM);
    if (rp == NULL) {

      dbg("out of mem\n");
      return NULL;
    }

    if (rp->len < sizeof(struct dhcp_msg)) {

      dbg("pbuf too small\n");
      pbuf_free(rp);
      return NULL;
    }

  struct dhcp_msg* resp = (struct dhcp_msg*)rp->payload;

  int len = p->len;

  if (rp->len < len)
    len = rp->len;

  memcpy(rp->payload, p->payload, len);
  memset(resp->options, 0, sizeof(resp->options));
  resp->op = 2; // reply
  resp->cookie = PP_HTONL(DHCP_MAGIC_COOKIE);

  return rp;
}

static void handleDiscover(struct pbuf* p, struct netif* netif)
{
  uint8_t * option_ptr;

  ip4_addr_t addr;
  struct dhcp_msg* req  = (struct dhcp_msg*)p->payload;

  if (allocateAddr((struct eth_addr*) req->chaddr, &addr) == 0) {

    struct pbuf* rp = newResp(p);
    if (rp == NULL)
      return;

    struct dhcp_msg* resp = (struct dhcp_msg*)rp->payload;

    ip4_addr_copy(resp->yiaddr, addr);
    option_ptr = (uint8_t *) &resp->options;

    addOptionByte(&option_ptr, OPT_MSGTYPE, DHCPOFFER);
    addOptionIP(&option_ptr, OPT_NETMASK, netif_ip4_netmask(netif));
    addOptionIP(&option_ptr, OPT_SERVERID, netif_ip4_addr(netif));
    *option_ptr++ = OPT_END;

    udp_sendto_if(dhcpPcb, rp, IP_ADDR_BROADCAST, LWIP_IANA_PORT_DHCP_CLIENT, netif);
    pbuf_free(rp);

    dbg("dhcps: offer %02X:%02X:%02X:%02X:%02X:%02X -> %s\n", resp->chaddr[0],
                                                                 resp->chaddr[1],
                                                                 resp->chaddr[2],
                                                                 resp->chaddr[3],
                                                                 resp->chaddr[4],
                                                                 resp->chaddr[5],
                                                                 inet_ntoa(addr));
  }
  else
    dbg("dhcps: no free addresses left.\n");

}

static void handleRequest(struct pbuf* p, struct netif* netif)
{
  uint8_t * option_ptr;
  ip4_addr_t newAddr;
  ip4_addr_t reqAddr;

  ip4_addr_set_zero(&reqAddr);
  struct dhcp_msg* req  = (struct dhcp_msg*)p->payload;

  if (allocateAddr((struct eth_addr*) req->chaddr, &newAddr) == 0) {

    struct pbuf* rp = newResp(p);
    if (rp == NULL)
      return;

    struct dhcp_msg* resp = (struct dhcp_msg*)rp->payload;

    // Find out what IP client is requesting.
    option_ptr = (uint8_t *) &req->options;
    while (getOption(option_ptr) != OPT_END) {

      int len = getOptionLen(option_ptr);

      switch (getOption(option_ptr)) {
      case OPT_REQ_IP:
        if (len == 4)
          memcpy(&reqAddr, getOptionData(option_ptr), 4);

        break;
      default:
        break;
      }

      nextOption(&option_ptr);
    }

    if (!memcmp(&reqAddr, &newAddr, 4) != 0) {

      ip4_addr_copy(resp->yiaddr, reqAddr);
      option_ptr = (uint8_t *) &resp->options;

      addOptionByte(&option_ptr, OPT_MSGTYPE, DHCPACK);
      addOptionTime(&option_ptr, OPT_RENEW_TIME, lease_time / 2 * 60);
      addOptionTime(&option_ptr, OPT_REBIND_TIME, lease_time * 7 / 8 * 60);
      addOptionTime(&option_ptr, OPT_LEASE_TIME, lease_time * 60);
      addOptionIP(&option_ptr, OPT_NETMASK, netif_ip4_netmask(netif));
      addOptionIP(&option_ptr, OPT_SERVERID, netif_ip4_addr(netif));
      *option_ptr++ = OPT_END;

      ip_addr_t dest;
      ip_addr_t* dp = &dest;

      ip_addr_set_ip4_u32(dp, ip4_addr_get_u32(&resp->yiaddr));
      etharp_add_static_entry(ip_2_ip4(dp), (struct eth_addr *) resp->chaddr);
      udp_sendto_if(dhcpPcb, rp, &dest, LWIP_IANA_PORT_DHCP_CLIENT, netif);
      pbuf_free(rp);

      dbg("dhcps: ack %02X:%02X:%02X:%02X:%02X:%02X -> %s\n", resp->chaddr[0],
                                                                 resp->chaddr[1],
                                                                 resp->chaddr[2],
                                                                 resp->chaddr[3],
                                                                 resp->chaddr[4],
                                                                 resp->chaddr[5],
                                                                 inet_ntoa(dest));
    }
    else {

      dbg("dhcps: Request IP %s is not free.\n", inet_ntoa(reqAddr));

      option_ptr = (uint8_t *) &resp->options;

      addOptionByte(&option_ptr, OPT_MSGTYPE, DHCPNAK);
      addOptionIP(&option_ptr, OPT_SERVERID, netif_ip4_addr(netif));
      *option_ptr++ = OPT_END;

      udp_sendto_if(dhcpPcb, rp, IP_ADDR_BROADCAST, LWIP_IANA_PORT_DHCP_CLIENT, netif);
      pbuf_free(rp);

    }
  }
  else
    dbg("dhcps: no free addresses left.\n");

}

uint32_t force_dhcp_release(struct eth_addr *mac)
{
    // search for existing
    for (int i = 0; i < MAX_LEASES; i++) {
      if (memcmp(mac->addr, leases[i].mac.addr, 6) == 0) {
        dbg("Dhcps release %d\r\n", i);
        memset(leases[i].mac.addr, 0, 6);
        dhcps_offered--;
        return 0;
      }
    }

    return 0;
}
static void handleRelese(struct pbuf* p, struct netif* netif)
{
    struct dhcp_msg* req  = (struct dhcp_msg*)p->payload;
    struct eth_addr eth_addr;
    memcpy(eth_addr.addr, req->chaddr, 6);
    force_dhcp_release(&eth_addr);
}

static void dhcpRecv(void* arg, struct udp_pcb* pcb, struct pbuf* p, const ip_addr_t* addr, u16_t port)
{
  struct netif *netif = (struct netif *)arg;
  struct dhcp_msg* req = (struct dhcp_msg*)p->payload;;

    dbg(D_INF "DHCP Server request received[%d]\n", req->options[2]);

      switch (req->options[2]) {

      case DHCPDISCOVER:
        handleDiscover(p, netif);
        break;

      case DHCPREQUEST:
        handleRequest(p, netif);
        break;

      case DHCPRELEASE:
        handleRelese(p, netif);
        break;

      default:
        dbg("DHCP unknown option %d\n", req->options[2]);
        break;
      }

  pbuf_free(p);
}

static void dhcpServerStartRaw(void* arg)
{
  struct netif *netif = (struct netif *)arg;

  memset(leases, '\0', sizeof(leases));
  const ip4_addr_t* base = netif_ip4_addr(netif);
  int i;

  for (i = 0; i < MAX_LEASES; i++) {

    IP4_ADDR(&leases[i].ip, ip4_addr1(base),
                            ip4_addr2(base),
                            ip4_addr3(base),
                            dhcps_start + i);
  }

  dhcpPcb = udp_new();
  if (dhcpPcb == NULL) {

    dbg("Cannot allocate dhcps pcb.\n");
    return;
  }

  ip_set_option(dhcpPcb, SOF_BROADCAST);
  udp_bind(dhcpPcb, IP_ADDR_ANY, LWIP_IANA_PORT_DHCP_SERVER);

  udp_recv(dhcpPcb, dhcpRecv, netif);
}

static void dhcpServerStopRaw(void* arg)
{
  udp_remove(dhcpPcb);
  dhcpPcb = NULL;
}

err_t dhcpServerStart(struct netif* netif)
{
  unsigned int ap_lease_time = 0;
  unsigned int ap_dhcp_start = 0;
  unsigned int ap_dhcp_end = 0;
  flash_wifi_lwip_dhcps_read(&ap_lease_time, &ap_dhcp_start, &ap_dhcp_end);
  if(ap_lease_time) {
      lease_time = ap_lease_time;
  }
  if(ap_dhcp_start) {
      dhcps_start = (ap_dhcp_start>>24)&0xFF;
  }
  fhost_cntrl_dhcps_release_register((fhost_cntrl_func_t)force_dhcp_release);
  dbg("dhcpServerStart %d %x, %x\r\n", ap_lease_time, ap_dhcp_start, ap_dhcp_end);
  return tcpip_callback(dhcpServerStartRaw, netif);
}

err_t dhcpServerStop(struct netif* netif)
{
  return tcpip_callback(dhcpServerStopRaw, netif);
}

uint32_t get_client_ip_by_index(uint8_t index)
{
    if (index < MAX_LEASES) {
        if (MAC_ADDR_VALID(leases[index].mac.addr) != 0)
            return leases[index].ip.addr;
    }
    dbg("Error: dhcp index[%d] unused! \r\n", index);
    return 0;
}

uint8_t get_client_ip_offered_cnt(void)
{
    return dhcps_offered;
}

