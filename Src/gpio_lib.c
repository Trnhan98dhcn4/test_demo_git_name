#include "..\Inc\gpio_lib.h"
#include <stdint.h>

void Gpio_Init()
{
	uint32_t* AHB1ENR = (uint32_t*)0x40023830;
	*AHB1ENR |= (0b1 << 0) | (0b1 << 3); 	// RCC GPIOA, GPIOD

	// set Input
	gpio_t* PortA_Moder = (gpio_t*)0x40020000;
	gpio_t* PortA_Pupdr = (gpio_t*)0x4002000c;
	PortA_Moder->MODER.MODER0 = INPUT_MODE;
	PortA_Pupdr->PUPDR.PUPDR0 = UP_DOWN;

	// set output
	gpio_t* PortD_Moder = (gpio_t*)0x40020c00;
	gpio_t* PortD_Otyper = (gpio_t*)0x40020c04;

	PortD_Moder->MODER.MODER12 = OUTPUT_MODE;
	PortD_Moder->MODER.MODER13 = OUTPUT_MODE;
	PortD_Moder->MODER.MODER14 = OUTPUT_MODE;
	PortD_Moder->MODER.MODER15 = OUTPUT_MODE;

	PortD_Otyper->OTYPER.OT12 = PUSH_PULL;
	PortD_Otyper->OTYPER.OT13 = PUSH_PULL;
	PortD_Otyper->OTYPER.OT14 = PUSH_PULL;
	PortD_Otyper->OTYPER.OT15 = PUSH_PULL;
}

void ctro_led(led_num_t Led_num, state_t State)
{
	gpio_t* PortD_Odr = (gpio_t*)0x40020c14;
	if(State == led_on)
	{
		PortD_Odr->ODR.value |= (0b1 << Led_num);
	}
	else
	{
		PortD_Odr->ODR.value &= ~(0b1 << Led_num);
	}
}


char button()
{
	gpio_t* PortA_IDR = (gpio_t*)0x40020010;
	return (PortA_IDR->IDR.IDR0 & 1);
}
