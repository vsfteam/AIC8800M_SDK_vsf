/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Simon Goldschmidt
 *
 */
#ifndef LWIP_HDR_LWIPOPTS_H__
#define LWIP_HDR_LWIPOPTS_H__

#include "rwnx_config.h"

#include "rtos.h"
#include "fhost_rx_def.h"

#if defined(LWIP_TIMEVAL_PRIVATE) && !LWIP_TIMEVAL_PRIVATE
#   include <time.h>
#endif

uint16_t fhost_ip_chksum(const void *dataptr, int len);

#define LWIP_NETIF_API                1

#define TCPIP_MBOX_SIZE               10
#define TCPIP_THREAD_STACKSIZE        TASK_STACK_SIZE_WIFI_TCPIP
#define TCPIP_THREAD_PRIO             TASK_PRIORITY_WIFI_TCPIP

#define DEFAULT_THREAD_STACKSIZE      1024
#define DEFAULT_THREAD_PRIO           1
#define DEFAULT_RAW_RECVMBOX_SIZE     32
#define DEFAULT_UDP_RECVMBOX_SIZE     32
#define DEFAULT_TCP_RECVMBOX_SIZE     32
#define DEFAULT_ACCEPTMBOX_SIZE       32

#define LWIP_NETIF_LOOPBACK           1
#define LWIP_HAVE_LOOPIF              1
#define LWIP_LOOPBACK_MAX_PBUFS       0

#define LWIP_CHKSUM_ALGORITHM         3
#define LWIP_CHKSUM                   fhost_ip_chksum
#define LWIP_TCPIP_CORE_LOCKING_INPUT 1

#define PBUF_LINK_ENCAPSULATION_HLEN  0

#define IP_REASS_MAX_PBUFS            (FHOST_RX_BUF_CNT - 2)

#ifndef MEMP_NUM_NETBUF
#define MEMP_NUM_NETBUF               32
#endif
#ifndef MEMP_NUM_NETCONN
#define MEMP_NUM_NETCONN              10
#endif
#ifndef MEMP_NUM_UDP_PCB
#define MEMP_NUM_UDP_PCB              16
#endif
#define MEMP_NUM_REASSDATA            LWIP_MIN((IP_REASS_MAX_PBUFS), 5)

#if NX_TXDESC_CNT0 > NX_TXDESC_CNT1
#define MAC_TXQ_DEPTH_0_1             NX_TXDESC_CNT0
#else
#define MAC_TXQ_DEPTH_0_1             NX_TXDESC_CNT1
#endif
#if NX_TXDESC_CNT2 > NX_TXDESC_CNT3
#define MAC_TXQ_DEPTH_2_3             NX_TXDESC_CNT2
#else
#define MAC_TXQ_DEPTH_2_3             NX_TXDESC_CNT3
#endif
#if MAC_TXQ_DEPTH_0_1 > MAC_TXQ_DEPTH_2_3
#define MAC_TXQ_DEPTH                 MAC_TXQ_DEPTH_0_1
#else
#define MAC_TXQ_DEPTH                 MAC_TXQ_DEPTH_2_3
#endif
#if NX_REORD
#define MAC_RXQ_DEPTH                 NX_REORD_BUF_SIZE
#else
#define MAC_RXQ_DEPTH                 4
#endif

#define TCP_MSS                       1460
#if NX_TLS
#define TCP_WND                       (MAC_RXQ_DEPTH * TCP_MSS / 4)
#else
#ifdef CFG_HS_IPERF
#define TCP_WND                       (5 * MAC_RXQ_DEPTH * TCP_MSS / 3)
#else
#if defined(CONFIG_RWNX_LWIP) && defined(CFG_HOSTIF)
#define TCP_WND                       (4 * MAC_RXQ_DEPTH * TCP_MSS)
#else /* CONFIG_RWNX_LWIP & CFG_HOSTIF */
#define TCP_WND                       (2 * MAC_RXQ_DEPTH * TCP_MSS)
#endif /* CONFIG_RWNX_LWIP & CFG_HOSTIF */
#endif
#endif
#define TCP_SND_BUF                   (2 * MAC_TXQ_DEPTH * TCP_MSS)
#define TCP_QUEUE_OOSEQ               1
#define MEMP_NUM_TCP_SEG              ((4 * TCP_SND_BUF) / TCP_MSS)
#if defined(CONFIG_RWNX_LWIP) && defined(CFG_HOSTIF)
#define MEMP_NUM_PBUF                 ((4 * TCP_SND_BUF) / TCP_MSS)
#else /* CONFIG_RWNX_LWIP && CFG_HOSTIF */
#define MEMP_NUM_PBUF                 ((2 * TCP_SND_BUF) / TCP_MSS)
#endif /* CONFIG_RWNX_LWIP && CFG_HOSTIF */
#define PBUF_POOL_SIZE                0
#ifdef CFG_HS_IPERF
#define LWIP_WND_SCALE                2
#else
#define LWIP_WND_SCALE                1
#endif
#define TCP_RCV_SCALE                 2
#define TCP_SNDLOWAT                  LWIP_MIN(LWIP_MAX(((TCP_SND_BUF)/4),               \
                                                        (2 * TCP_MSS) + 1),              \
                                               (TCP_SND_BUF) - 1)

#define MEM_MIN_TCP                   (2300 + MEMP_NUM_PBUF * (100 + PBUF_LINK_ENCAPSULATION_HLEN))
#if NX_TG
#define MEM_MIN_TG                    16384
#else
#define MEM_MIN_TG                    0
#endif
#if MEM_MIN_TCP > MEM_MIN_TG
#define MEM_MIN                       MEM_MIN_TCP
#else
#define MEM_MIN                       MEM_MIN_TG
#endif
#define MEM_ALIGNMENT                 4
#if PLF_WIFI_AUDIO
#define MEM_SIZE                      0x3000
#else
#if MEM_MIN > 8192
#define MEM_SIZE                      MEM_MIN
#else
#define MEM_SIZE                      8192
#endif
#endif

#define LWIP_HOOK_FILENAME            "lwiphooks.h"

#define LWIP_RAW                      1
#define LWIP_MULTICAST_TX_OPTIONS     1

//#define LWIP_TIMEVAL_PRIVATE          0  // use sys/time.h for struct timeval
#define LWIP_PROVIDE_ERRNO            1

#define LWIP_DHCP                     1
#define LWIP_DNS                      1
#define LWIP_NETIF_HOSTNAME           1

/* Enable IGMP and MDNS for MDNS tests */
#define LWIP_IGMP                       1
#define LWIP_MDNS_RESPONDER             1
#define LWIP_NUM_NETIF_CLIENT_DATA      (LWIP_MDNS_RESPONDER)

#define DNS_TABLE_SIZE                  6
#if PLF_SNTP
#define SNTP_CHECK_RESPONSE             0
#define SNTP_RECV_TIMEOUT               1500
#define LWIP_SNTP                       10
#define SNTP_SERVER_DNS                 1
#define LWIP_DHCP_MAX_NTP_SERVERS       6
#if SNTP_SERVER_DNS
#define SNTP_SERVER_ADDRESS            "pool.ntp.org"
#if 1
#define SNTP_SERVER_ADDRESS1            "ntp.aliyun.com"
#define SNTP_SERVER_ADDRESS2            "ntp.nict.jp"
#define SNTP_SERVER_ADDRESS3            "us.ntp.org.cn"
#define SNTP_SERVER_ADDRESS4            "ntps1-0.cs.tu-berlin.de"
#define SNTP_SERVER_ADDRESS5            "Time1.Stupi.SE"
#endif
#else
#define SNTP_SERVER_ADDRESS             0x0C431054
#if 1
#define SNTP_SERVER_ADDRESS1            0x58066BCB
#define SNTP_SERVER_ADDRESS2            0x8D6FB6C1
#define SNTP_SERVER_ADDRESS3            0xF3EEF385
#define SNTP_SERVER_ADDRESS4            0xCAFEDAD8
#define SNTP_SERVER_ADDRESS5            0x968F24C0
#endif
#endif
#else
#define LWIP_SNTP                       0
#endif
#define SNTP_SET_SYSTEM_TIME(sec)       sntp_time_update_and_show(sec, 0)

#if PLF_WIFI_AUDIO
#define LWIP_NETIF_TX_SINGLE_PBUF       1
#define LWIP_SUPPORT_CUSTOM_PBUF        1
#endif

#define LWIP_DNS_SUPPORT_MDNS_QUERIES  1

#if 0
/* Prevent having to link sys_arch.c (we don't test the API layers in unit tests) */
#define NO_SYS                          0
#define LWIP_NETCONN                    0
#define LWIP_SOCKET                     0
#define SYS_LIGHTWEIGHT_PROT            0

#define LWIP_IPV6                       1
#define IPV6_FRAG_COPYHEADER            1
#define LWIP_IPV6_DUP_DETECT_ATTEMPTS   0

/* Turn off checksum verification of fuzzed data */
#define CHECKSUM_CHECK_IP               0
#define CHECKSUM_CHECK_UDP              0
#define CHECKSUM_CHECK_TCP              0
#define CHECKSUM_CHECK_ICMP             0
#define CHECKSUM_CHECK_ICMP6            0

/* Minimal changes to opt.h required for tcp unit tests: */
#define MEM_SIZE                        16000
#define TCP_SND_QUEUELEN                40
#define MEMP_NUM_TCP_SEG                TCP_SND_QUEUELEN
#define TCP_SND_BUF                     (12 * TCP_MSS)
#define TCP_WND                         (10 * TCP_MSS)
#define LWIP_WND_SCALE                  1
#define TCP_RCV_SCALE                   0
#define PBUF_POOL_SIZE                  400 /* pbuf tests need ~200KByte */

/* Minimal changes to opt.h required for etharp unit tests: */
#define ETHARP_SUPPORT_STATIC_ENTRIES   1
#endif

#endif /* LWIP_HDR_LWIPOPTS_H__ */
