#include "platform_types.h"

#define RCC_BASE 	0x40021000
#define GPIO_PA_BASE 	0x40010800
#define RCC_APB2ENR	*((vuint32_t*)(RCC_BASE+0X18))
#define GPIOA_CRH	*((vuint32_t*)(GPIO_PA_BASE+0X04))
#define GPIOA_ODR	*((vuint32_t*)(GPIO_PA_BASE+0X0C))

typedef union{
	vuint32_t allfields;
	struct{
		vuint32_t reserved:13;
		vuint32_t p13:1;
	}pin;
}R_ODR;

volatile R_ODR* PR_ORD=(R_ODR*)(GPIO_PA_BASE+0x0c);
unsigned char g_variables[3] = {1,2,3};
unsigned char const const_variables[3] = {1,2,3};
volatile unsigned char bss_variable[3];

int main(void)
{
	RCC_APB2ENR |=1<<2;
	GPIOA_CRH &=0xff0fffff;
	GPIOA_CRH |=0x00200000;
	while(1)
	{
		PR_ORD->pin.p13=1;
		int i;
		for(i=0;i<5000;++i);
		PR_ORD->pin.p13=0;
		for(i=0;i<5000;++i);

	}
	return 0;
}
