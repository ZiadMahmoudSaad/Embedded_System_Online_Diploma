ENTRY(reset)

MEMORY
{
	MEM(rwx) : ORIGIN = 0X00000000,LENGTH = 64M 
}

SECTIONS{
	. =0X10000;
	.startup . :
	{
		startup.o(.text)
	}> MEM
	.text :
	{
		*(.text) *(.rodata)
	}> MEM
	.bss :
	{
		*(.bss) *(COMMON)
	}> MEM
	. = . + 0X1000;
	stack_top = . ;
}