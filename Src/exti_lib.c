#include <stdint.h>
#include "..\Inc\exti_lib.h"
#include "..\Inc\gpio_lib.h"

#define SYSCFG_BASE_ADDRESS 0x40013800
#define EXTI_BASE_ADDRESS 0x40013C00
#define NVIC_ISER0_BASE_ADDRESS 0xE000E100

uint32_t dem = 0;

void EXTI0_Init()
{
    uint32_t* SYSCFG_EXTICR1 = (uint32_t*)(SYSCFG_BASE_ADDRESS + 0x08);
    *SYSCFG_EXTICR1 &= ~(0b111 << 0);
    uint32_t* EXTI_FTSR = (uint32_t*)(EXTI_BASE_ADDRESS + 0x0C);
    *EXTI_FTSR |= (0b1 << 0);
    uint32_t* EXTI_IMR = (uint32_t*)(EXTI_BASE_ADDRESS + 0x00);
    *EXTI_IMR |= (0b1 << 0);

    uint32_t* NVIC_ISER0 = (uint32_t*)(NVIC_ISER0_BASE_ADDRESS + 0x00);
    *NVIC_ISER0 |= (0b1 << 6);
}

void EXTI0_Custom_Handler()
{    
    dem++;
    if(dem % 2 == 0)
    {
        ctro_led(led_0, led_on);
		ctro_led(led_1, led_on);
		ctro_led(led_2, led_on);
		ctro_led(led_3, led_on);
    }
    else
    {
        ctro_led(led_0, led_off);
		ctro_led(led_1, led_off);
		ctro_led(led_2, led_off);
		ctro_led(led_3, led_off);
    }
    uint32_t* EXTI0_PR = (uint32_t*)(EXTI_BASE_ADDRESS + 0x14);
    *EXTI0_PR |= (0b1 << 0);
}