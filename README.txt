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
