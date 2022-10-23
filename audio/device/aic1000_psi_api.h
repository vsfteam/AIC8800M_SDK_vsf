#ifndef _AIC1000_PSI_API_H_
#define _AIC1000_PSI_API_H_

void psi_io_init(void);
void psi_write_op(unsigned int waddr,unsigned int wdata);
unsigned int psi_read_op(unsigned int raddr);
void psi_mask_write_op(unsigned int waddr,unsigned int wdata,unsigned int mask);

#endif
