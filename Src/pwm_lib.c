#include <stdint.h>
#include "../Inc/pwm_lib.h"
#include "../Inc/gpio_lib.h"
#include "../Inc/rcc_lib.h"

void PWM_Output_Compare()
{
    uint32_t* RCC_AHB1ENR = (uint32_t*)(RCC_BASE_ADDRESS + 0x30);
    *RCC_AHB1ENR |= (0b1 << 3);                                          //enable RCC GPIOD

    gpio_t* PortD_Moder = (gpio_t*)(POERD_BASE_ADDR + 0x00);
    PortD_Moder->MODER.MODER12 = ALTERNATE_FUNCTION_MODE;
    PortD_Moder->MODER.MODER13 = ALTERNATE_FUNCTION_MODE;
    PortD_Moder->MODER.MODER14 = ALTERNATE_FUNCTION_MODE;
    PortD_Moder->MODER.MODER15 = ALTERNATE_FUNCTION_MODE;

    gpio_t* PortD_AFRH = (gpio_t*)(POERD_BASE_ADDR + 0x24);
    PortD_AFRH->AFRH.AFRH12 = AF2;
    PortD_AFRH->AFRH.AFRH13 = AF2;
    PortD_AFRH->AFRH.AFRH14 = AF2;
    PortD_AFRH->AFRH.AFRH15 = AF2;

    uint32_t* RCC_APB1ENR = (uint32_t*)(RCC_BASE_ADDRESS + 0x40);
    *RCC_APB1ENR |= (0b1 << 2);                                          //enable RCC TIM4

    uint16_t* TIM4_CR = (uint16_t*)(TIME4_BASE_ADDR + 0x00);
    uint16_t* TIM4_ARR = (uint16_t*)(TIME4_BASE_ADDR + 0x2C);
    uint16_t* TIM4_PSC = (uint16_t*)(TIME4_BASE_ADDR + 0x28);
    uint16_t* TIM4_CCR1 = (uint16_t*)(TIME4_BASE_ADDR + 0x34);
    uint16_t* TIM4_CCR2 = (uint16_t*)(TIME4_BASE_ADDR + 0x38);
    uint16_t* TIM4_CCR3 = (uint16_t*)(TIME4_BASE_ADDR + 0x3C);
    uint16_t* TIM4_CCR4 = (uint16_t*)(TIME4_BASE_ADDR + 0x40);

    *TIM4_ARR = 99;
    *TIM4_PSC = 160;
    *TIM4_CR |= (0b1 << 0);

    *TIM4_CCR1 = 1;                                                    // do rong xung
    *TIM4_CCR2 = 1;
    *TIM4_CCR3 = 1;
    *TIM4_CCR4 = 1;
    
    uint16_t* TIM4_CCMR1 = (uint16_t*)(TIME4_BASE_ADDR + 0x18);
    *TIM4_CCMR1 &= ~(0b11 << 0);                                        // set channel 1 output compare PD_12
    *TIM4_CCMR1 &= ~(0b11 << 8);                                        // set channel 2 output compare PD_13
    *TIM4_CCMR1 |= (0b110 << 4) | (0b110 << 12);                        // set PWM1 mode

    uint16_t* TIM4_CCMR2 = (uint16_t*)(TIME4_BASE_ADDR + 0x1C);
    *TIM4_CCMR2 &= ~(0b11 << 0);                                        // set channel 3 output compare PD_14
    *TIM4_CCMR2 &= ~(0b11 << 8);                                        // set channel 4 output compare PD_15
    *TIM4_CCMR2 |= (0b110 << 4) | (0b110 << 12);                        // set PWM1 mode

    uint16_t* TIM4_CCER = (uint16_t*)(TIME4_BASE_ADDR + 0x20);
    *TIM4_CCER |= (0b1 << 0) | (0b1 << 4) | (0b1 << 8) | (0b1 << 12);
}

void Modify_PWM(uint8_t value)
{
    uint16_t* TIM4_CCR1 = (uint16_t*)(TIME4_BASE_ADDR + 0x34);
    uint16_t* TIM4_CCR2 = (uint16_t*)(TIME4_BASE_ADDR + 0x38);
    uint16_t* TIM4_CCR3 = (uint16_t*)(TIME4_BASE_ADDR + 0x3C);
    uint16_t* TIM4_CCR4 = (uint16_t*)(TIME4_BASE_ADDR + 0x40);

    *TIM4_CCR1 = value;
    *TIM4_CCR2 = value;
    *TIM4_CCR3 = value;
    *TIM4_CCR4 = value;
}