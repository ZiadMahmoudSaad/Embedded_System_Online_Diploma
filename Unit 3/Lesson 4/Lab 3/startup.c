/*startup.c
Eng.Ziad
*/

#include <stdint.h>

extern int main(void);
void Reset_Handler();
void Default_Handler();

void NMI_Handler()__attribute__((weak, alias("Default_Handler")));
void H_Fault_Handler()__attribute__((weak, alias("Default_Handler")));

extern unsigned int _E_text;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

static unsigned long Stack_top[256];

void (* const g_p_fn_Vectors[])() __attribute__((section(".vectors")))=
{
	(void(*)()) ((unsigned long)Stack_top + sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_Fault_Handler
};


void Reset_Handler()
{
	unsigned int DATA_size	= (unsigned char *)&_E_DATA - (unsigned char *)&_S_DATA;
	unsigned int bss_size	= (unsigned char *)&_E_bss - (unsigned char *)&_S_bss;

	unsigned char *P_src	=(unsigned char *)&_E_text;
	unsigned char *P_dst	=(unsigned char *)&_S_DATA;

	for (int i = 0; i < DATA_size; ++i)
	{
		*((unsigned char *)P_dst++) = *((unsigned char *)P_src++);
	}

	P_dst =(unsigned char *)&_S_bss;
	for (int i = 0; i < bss_size; ++i)
	{
		*((unsigned char *)P_dst++) = (unsigned char)0;
	}

	main();
}

void Default_Handler()
{
	Reset_Handler();
}