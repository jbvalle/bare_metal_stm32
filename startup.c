#include <stdint.h>

//SRAM1 96Kbytes starts at 0x2000 0000 - 0x2001 7FFF 
#define SRAM_START 0x20000000U
#define SRAM_SIZE (96 * 1024) //96KB
#define SRAM_END ((SRAM_START) + (SRAM_SIZE))

#define STACK_START SRAM_END

extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _etext;

int main(void);

void Reset_handler          (void);
void NMI_handler            (void)__attribute__((weak, alias("Default_handler")));
void HardFault_handler      (void)__attribute__((weak, alias("Default_handler")));
void MemManage_handler      (void)__attribute__((weak, alias("Default_handler")));
void BusFault_handler       (void)__attribute__((weak, alias("Default_handler")));
void UsuageFault_handler    (void)__attribute__((weak, alias("Default_handler")));
void SVCall_handler         (void)__attribute__((weak, alias("Default_handler")));
void DebugMonitor_handler   (void)__attribute__((weak, alias("Default_handler")));
void PendSV_handler         (void)__attribute__((weak, alias("Default_handler")));
void Systick_handler        (void)__attribute__((weak, alias("Default_handler")));
void WWDG_handler                 (void)__attribute__((weak, alias("Default_handler")));
void EXITI16_PVD__handler         (void)__attribute__((weak, alias("Default_handler")));
void EXITI21_TAMP_STAMP_handler   (void)__attribute__((weak, alias("Default_handler")));
void EXITI22_RTC_WKUP_handler     (void)__attribute__((weak, alias("Default_handler")));
void FLASH_handler                (void)__attribute__((weak, alias("Default_handler")));
void RCC_handler                  (void)__attribute__((weak, alias("Default_handler")));
void EXTI0_handler                (void)__attribute__((weak, alias("Default_handler")));
void EXTI1_handler                (void)__attribute__((weak, alias("Default_handler")));
void EXTI2_handler                (void)__attribute__((weak, alias("Default_handler")));
void EXTI3_handler                (void)__attribute__((weak, alias("Default_handler")));
void EXTI4_handler                (void)__attribute__((weak, alias("Default_handler")));
void DMA1_Stream0_handler         (void)__attribute__((weak, alias("Default_handler")));
void DMA1_Stream1_handler         (void)__attribute__((weak, alias("Default_handler")));
void DMA1_Stream2_handler         (void)__attribute__((weak, alias("Default_handler")));
void DMA1_Stream3_handler         (void)__attribute__((weak, alias("Default_handler")));
void DMA1_Stream4_handler         (void)__attribute__((weak, alias("Default_handler")));
void DMA1_Stream5_handler         (void)__attribute__((weak, alias("Default_handler")));
void DMA1_Stream6_handler         (void)__attribute__((weak, alias("Default_handler")));
void ADC_handler                  (void)__attribute__((weak, alias("Default_handler")));
void EXTI9_5__handler             (void)__attribute__((weak, alias("Default_handler")));
void TIM1_BRK_TIM9_handler        (void)__attribute__((weak, alias("Default_handler")));
void TIM1_UP_TIM10_handler        (void)__attribute__((weak, alias("Default_handler")));
void TIM1_TRG_COM_TIM11_handler   (void)__attribute__((weak, alias("Default_handler")));
void TIM1_CC_handler              (void)__attribute__((weak, alias("Default_handler")));
void TIM2_handler                 (void)__attribute__((weak, alias("Default_handler")));
void TIM3_handler                 (void)__attribute__((weak, alias("Default_handler")));
void TIM4_handler                 (void)__attribute__((weak, alias("Default_handler")));
void I2C1_EV_handler              (void)__attribute__((weak, alias("Default_handler")));
void I2C1_ER_handler              (void)__attribute__((weak, alias("Default_handler")));
void I2C2_EV_handler              (void)__attribute__((weak, alias("Default_handler")));
void I2C2_ER_handler              (void)__attribute__((weak, alias("Default_handler")));
void SPI1_handler                 (void)__attribute__((weak, alias("Default_handler")));
void SPI2_handler                 (void)__attribute__((weak, alias("Default_handler")));
void UART1_handler                (void)__attribute__((weak, alias("Default_handler")));
void UART2_handler                (void)__attribute__((weak, alias("Default_handler")));
void EXTI15_10_handler            (void)__attribute__((weak, alias("Default_handler")));
void EXTI17_RTC_Alarm_handler     (void)__attribute__((weak, alias("Default_handler")));
void EXTI18_OTG_FS_WKUP_handler   (void)__attribute__((weak, alias("Default_handler")));
void DMA1_Stream7_handler         (void)__attribute__((weak, alias("Default_handler")));
void SDIO_handler                 (void)__attribute__((weak, alias("Default_handler")));
void TIM5_handler                 (void)__attribute__((weak, alias("Default_handler")));
void SPI3_handler                 (void)__attribute__((weak, alias("Default_handler")));
void DMA2_Stream0_handler                 (void)__attribute__((weak, alias("Default_handler")));
void DMA2_Stream1_handler                 (void)__attribute__((weak, alias("Default_handler")));
void DMA2_Stream2_handler                 (void)__attribute__((weak, alias("Default_handler")));
void DMA2_Stream3_handler                 (void)__attribute__((weak, alias("Default_handler")));
void DMA2_Stream4_handler                 (void)__attribute__((weak, alias("Default_handler")));
void OTG_FS_handler                       (void)__attribute__((weak, alias("Default_handler")));
void DMA2_Stream5_handler                 (void)__attribute__((weak, alias("Default_handler")));
void DMA2_Stream6_handler                 (void)__attribute__((weak, alias("Default_handler")));
void DMA2_Stream7_handler                 (void)__attribute__((weak, alias("Default_handler")));
void UART6_handler                        (void)__attribute__((weak, alias("Default_handler")));
void I2C3_EV_handler                      (void)__attribute__((weak, alias("Default_handler")));
void I2C3_ER_handler                      (void)__attribute__((weak, alias("Default_handler")));
void FPU_handler                          (void)__attribute__((weak, alias("Default_handler")));
void SPI4_handler                         (void)__attribute__((weak, alias("Default_handler")));

uint32_t  vector[] __attribute__((section(".isr_vector")))= {
    STACK_START,
    (uint32_t)Reset_handler,
    (uint32_t)NMI_handler,
    (uint32_t)HardFault_handler,
    (uint32_t)MemManage_handler,
    (uint32_t)BusFault_handler,
    (uint32_t)UsuageFault_handler,
    0,
    0,
    0,
    0,
    (uint32_t)SVCall_handler,
    (uint32_t)DebugMonitor_handler,
    0,
    (uint32_t)PendSV_handler,
    (uint32_t)Systick_handler,
    (uint32_t)WWDG_handler,
    (uint32_t)EXITI16_PVD__handler,
    (uint32_t)EXITI21_TAMP_STAMP_handler,
    (uint32_t)EXITI22_RTC_WKUP_handler,
    (uint32_t)FLASH_handler,
    (uint32_t)RCC_handler,
    (uint32_t)EXTI0_handler,
    (uint32_t)EXTI1_handler,
    (uint32_t)EXTI2_handler,
    (uint32_t)EXTI3_handler,
    (uint32_t)EXTI4_handler,
    (uint32_t)DMA1_Stream0_handler,
    (uint32_t)DMA1_Stream1_handler,
    (uint32_t)DMA1_Stream2_handler,
    (uint32_t)DMA1_Stream3_handler,
    (uint32_t)DMA1_Stream4_handler,
    (uint32_t)DMA1_Stream5_handler,
    (uint32_t)DMA1_Stream6_handler,
    (uint32_t)ADC_handler,
    (uint32_t)EXTI9_5__handler,
    (uint32_t)TIM1_BRK_TIM9_handler,
    (uint32_t)TIM1_UP_TIM10_handler,
    (uint32_t)TIM1_TRG_COM_TIM11_handler,
    (uint32_t)TIM2_handler,
    (uint32_t)TIM3_handler,
    (uint32_t)TIM4_handler,
    (uint32_t)I2C1_EV_handler,
    (uint32_t)I2C1_ER_handler,
    (uint32_t)I2C2_EV_handler,
    (uint32_t)I2C2_ER_handler,
    (uint32_t)SPI1_handler,
    (uint32_t)SPI2_handler,
    (uint32_t)UART1_handler,
    (uint32_t)UART2_handler,
    (uint32_t)EXTI17_RTC_Alarm_handler,
    (uint32_t)EXTI18_OTG_FS_WKUP_handler,
    (uint32_t)DMA1_Stream7_handler,
    (uint32_t)SDIO_handler,
    (uint32_t)TIM5_handler,
    (uint32_t)SPI3_handler,
    (uint32_t)DMA2_Stream0_handler,
    (uint32_t)DMA2_Stream1_handler,
    (uint32_t)DMA2_Stream2_handler,
    (uint32_t)DMA2_Stream3_handler,
    (uint32_t)DMA2_Stream4_handler,
    (uint32_t)OTG_FS_handler,
    (uint32_t)DMA2_Stream5_handler,
    (uint32_t)DMA2_Stream6_handler,
    (uint32_t)DMA2_Stream7_handler,
    (uint32_t)UART6_handler,
    (uint32_t)I2C3_EV_handler,
    (uint32_t)I2C3_ER_handler,
    (uint32_t)FPU_handler,
    (uint32_t)SPI4_handler,
};

void Default_handler(void){
    for(;;);
}

void Reset_handler(void){

    /***********************************/
    /** 1. Copy .data section to sram **/
    /***********************************/
    // Boundaries needed: _edata, _sdata, _etext
    uint32_t size = &_edata - &_sdata;

    uint8_t *pDst = (uint8_t *)&_sdata;
    uint8_t *pSrc = (uint8_t *)&_etext;

    for(uint32_t i = 0; i < size; i++){

        *pDst++ = *pSrc++;
    }
    /**********************************************/
    /** 2. Init the .bss section to zero in sram **/
    /**********************************************/
    //1. Retrieve bss size
    size = &_ebss - &_sbss;
    //2. Retrieve bss destination address
    pDst = (uint8_t *)&_sbss;
    //3. Initialize bss values with 0
    for(uint8_t i = 0; i < size; i++){

        *pDst++ = 0;
    }
    /**************************************************/
    /** Option: Call Init() function for std library **/
    /**************************************************/

    /********************/
    /** 3. Call main() **/
    /********************/
    main();
}
