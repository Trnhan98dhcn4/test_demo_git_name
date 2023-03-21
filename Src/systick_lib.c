#include <stdint.h>
#include "..\Inc\systick_lib.h"

int tick = 0;
uint32_t* STCSR = (uint32_t*)0xe000e010;
uint32_t* STRVR = (uint32_t*)0xe000e014;

void Delay_Init()
{
	*STRVR = 1000;								//chon tan so cho xung
	*STCSR |= 0b1 | (0b1 << 1);					// enable systick, interrupt
}

void Systick_custom_Handler()
{
	tick++;
	*STCSR &= ~(0b1 << 16);
}

void delay_ms(uint32_t ms)
{
	tick = 0;
	while(tick < ms);
}