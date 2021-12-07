#ifndef _DHCPS_H_
#define _DHCPS_H_

#include <stdio.h>
#include <string.h>
#include "lwip/arch.h"
#include "lwip/netif.h"
#include "lwip/udp.h"
#include "lwip/stats.h"
#include "lwip/sys.h"
#include "ethernet.h"

err_t dhcpServerStart(struct netif* netif);

err_t dhcpServerStop(struct netif* netif);

uint32_t get_client_ip_by_index(uint8_t index);

uint8_t get_client_ip_offered_cnt(void);

#endif /* _DHCPS_H_ */
