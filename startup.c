#include <stdint.h>

//SRAM1 128Kbytes starts at 0x2000 0000
//SRAM2 32Kbytes
#define SRAM_START 0x20000000U
#define SRAM_SIZE (128 * 1024) //128KB
#define SRAM_END ((SRAM_START) + (SRAM_SIZE))

#define STACK_START SRAM_END

void Reset_handler(void);

uint32_t  vector[] __attribute__((section(".isr_vector")))= {
  STACK_START,
  (uint32_t)&Reset_handler,
};

void Reset_handler(){

}
