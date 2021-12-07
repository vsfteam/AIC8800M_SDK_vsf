#ifndef _FHOST_MDNS_
#define _FHOST_MDNS_

int fhost_mdns_start(void);

int fhost_mdns_stop(void);
void fhost_mdns_set_param(char *hName, char *sName, uint16_t port);

#endif /* _FHOST_MDNS_ */
