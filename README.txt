Importance of Startup:
* takes care of vector table placement in code memory

Sequence:
1. Create vector table for your uC
2. Init .data and .bss in SRAM
3. Call main

Linker and Locator:
* Defines how sections will be merged
* Linker and location assign absolute addresses to sections based on the address information in the linker script
* include code and data memory addresses and size information
* Written in GNU linker command language
* Linker script must be supplied in linking stage using -T

ENTRY Command:
* used to set the entry point address in th header of final .elf file
* Debugger uses this information to locate first function
* Entry command is optional, however its important for debugging purposes for the gdb
* Syntax
Entry(_symbol_name_)
Entry(Reset_handler)

Memory Command:
* Allows to describe the different memories present in the target as well as their start address and size
* linker uses this information to assign addresses to merged sections
* The information also helps linker to calculate the total code and data memory consumed and throw an eror if data, code, heap or stack areas dont fit
* Allows to fine tune memories in target and allow different sections to occupy different memory areas
* Typically one linker script has one memory command
* Syntax:
Memory
{
    name(opt: attr) : ORIGIN = origin, length = len
}

* label: name -> defines name of the memory region which can be referenced to inside the linker script
* keyword: ORIGIN -> defines origin address of the memory region
* keyword: LENGTH -> defines the length information
* attr:
- R : Read only section
- W : Read and write section
- X : Section containing executable code
- A : Allocated sections
- I : Initialized sections
- L : Same as I
- ! : Invert the sense of any of the following attributes

STM32F401RE Memory Information:
* 512KB/0x8 0000 of Flash memory -> 0x0800 0000 - 0x0807 FFFF
*  96KB/0x1 8000 of System SRAM  -> 0x2000 0000 - 0x2001 7FFF

Section Command:
* used to create different output sections in the final elf executable
* used to instruct linker how to merge input sections to yield an output section
* Controls the order in which different output sections appear in the elf file
* Section command dictates placement