#ifndef _PSIM_API_H_
#define _PSIM_API_H_

void psim_init(void);
unsigned int psim_read(unsigned int addr);
void psim_write(unsigned int addr, unsigned int data);
void psim_mask_write(unsigned int addr, unsigned int data, unsigned int mask);

#endif /* _PSIM_API_H_ */
