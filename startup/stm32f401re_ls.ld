ENTRY(Reset_handler)

/***************************/
/** Highes adress of stack**/
/***************************/
_estack = 0x20000000 + 96K;

/******************/
/** Memory Areas **/
/******************/

MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 96K
}

/*****************************/
/** Generate OUTPUT Sections **/
/*****************************/

SECTIONS
{
    .isr_vector :
    {
        . = ALIGN(4);
        KEEP*(.isr_vector)
        . = ALIGN(4);
    }> FLASH

    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.rodata)
        . = ALIGN(4);
        _etext = .;
    }> FLASH 

    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        . = ALIGN(4);
        _edata = .;
    }> SRAM AT> FLASH

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    }> SRAM

} 
