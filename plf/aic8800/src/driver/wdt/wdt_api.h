#ifndef _WDT_API_H_
#define _WDT_API_H_

void wdt_init(unsigned int seconds);
void wdt_kick(void);
void wdt_stop(void);

#endif /* _WDT_API_H_ */
