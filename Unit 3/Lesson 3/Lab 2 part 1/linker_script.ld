/*linker script CortexM3
Eng.Ziad
*/

MEMORY
{
	flash(RX) : ORIGIN = 0X08000000, LENGTH = 128k
	sram(RWX) : ORIGIN = 0X20000000, LENGTH = 20k
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata)
	}> flash

	.data : {
		*(.data)
	}> flash

	.bss : {
	*(.bss*)
	}> sram
}