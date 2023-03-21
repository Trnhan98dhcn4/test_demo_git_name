#include <stdint.h>
#include "..\Inc\rcc_lib.h"



void RCC_LSE_Init()
{
    uint32_t* CR = (uint32_t*)(RCC_BASE_ADDRESS + 0x00);
    uint32_t* CFGR = (uint32_t*)(RCC_BASE_ADDRESS + 0x08);
    *CR |= (0b1 << 16);
    while(((*CR >> 17) & 1) == 0);

    *CFGR |= (0b01 << 0);
}

void RCC_PLL_Init()
{
    uint32_t* CR = (uint32_t*)(RCC_BASE_ADDRESS + 0x00);
    uint32_t* PLLCFGR = (uint32_t*)(RCC_BASE_ADDRESS + 0x04);
    uint32_t* CFGR = (uint32_t*)(RCC_BASE_ADDRESS + 0x08);

    *CR |= (0b1 << 24);
    while(((*CR >> 25) & 1) == 0);
    
    *PLLCFGR &= ~(0b1 << 22);
    //16MHz ->(M/16) 1MHz -> N*(200) 200MHz -> (P/4) 50MHz
    *PLLCFGR |= (16 << 0) | (200 << 6) | (0b00 << 2);

    *CFGR |= (0b10 << 0);
}