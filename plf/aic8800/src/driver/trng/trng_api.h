#ifndef _TRNG_API_H_
#define _TRNG_API_H_

void trng_init(void);
void trng_free(void);
unsigned int trng_get_word(void);

#endif /* _TRNG_API_H_ */
