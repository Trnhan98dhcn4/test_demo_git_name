/*
 * gpio_lib.h
 *
 *  Created on: Feb 13, 2023
 *      Author: TrNhan
 */

#ifndef INC_GPIO_LIB_H_
#define INC_GPIO_LIB_H_
#include <stdint.h>

#define PORTB_BASE_ADDR 0x40020400
#define PORTC_BASE_ADDR 0x40020800
#define POERD_BASE_ADDR 0x40020C00
#define PORTE_BASE_ADDR 0x40021000
#define PORTA_BASE_ADDR 0x40020000

// MODER
#define INPUT_MODE 					0b00
#define OUTPUT_MODE 				0b01
#define ALTERNATE_FUNCTION_MODE 	0b10
#define ANALOG_MODE					0b11

//OTYPER
#define PUSH_PULL	0b0
#define OPEN_DRAIN	0b1

//PUPDR
#define UP_DOWN 	0b00;
#define PULL_UP		0b01;
#define PULL_DOWN	0b10;
#define	RESERVED	0b11;

//AFRL - AFRH
#define AF0 		0b0000
#define AF1			0b0001
#define AF2			0b0010
#define AF3			0b0011
#define AF4			0b0100
#define AF5			0b0101
#define AF6			0b0110
#define AF7			0b0111
#define AF8			0b1000
#define AF9			0b1001
#define AF10		0b1010
#define AF11		0b1011
#define AF12		0b1100
#define AF13		0b1101
#define AF14		0b1110
#define AF15		0b1111


#endif /* INC_GPIO_LIB_H_ */

typedef union
{
	struct
	{
		char MODER0: 2;
		char MODER1: 2;
		char MODER2: 2;
		char MODER3: 2;
		char MODER4: 2;
		char MODER5: 2;
		char MODER6: 2;
		char MODER7: 2;
		char MODER8: 2;
		char MODER9: 2;
		char MODER10: 2;
		char MODER11: 2;
		char MODER12: 2;
		char MODER13: 2;
		char MODER14: 2;
		char MODER15: 2;
	};
}moder_t;

typedef union
{
	struct
	{
		char OT0: 1;
		char OT1: 1;
		char OT2: 1;
		char OT3: 1;
		char OT4: 1;
		char OT5: 1;
		char OT6: 1;
		char OT7: 1;
		char OT8: 1;
		char OT9: 1;
		char OT10: 1;
		char OT11: 1;
		char OT12: 1;
		char OT13: 1;
		char OT14: 1;
		char OT15: 1;
	};
}otyper_t;

typedef union
{
	struct
	{
		char OSPEED0: 2;
		char OSPEED1: 2;
		char OSPEED2: 2;
		char OSPEED3: 2;
		char OSPEED4: 2;
		char OSPEED5: 2;
		char OSPEED6: 2;
		char OSPEED7: 2;
		char OSPEED8: 2;
		char OSPEED9: 2;
		char OSPEED10: 2;
		char OSPEED11: 2;
		char OSPEED12: 2;
		char OSPEED13: 2;
		char OSPEED14: 2;
		char OSPEED15: 2;
	};
	uint32_t value;
}ospeed_t;

typedef union
{
	struct
	{
		char PUPDR0 : 2;
		char PUPDR1 : 2;
		char PUPDR2 : 2;
		char PUPDR3 : 2;
		char PUPDR4 : 2;
		char PUPDR5 : 2;
		char PUPDR6 : 2;
		char PUPDR7 : 2;
		char PUPDR8 : 2;
		char PUPDR9 : 2;
		char PUPDR10 : 2;
		char PUPDR11 : 2;
		char PUPDR12 : 2;
		char PUPDR13 : 2;
		char PUPDR14 : 2;
		char PUPDR15 : 2;
	};
	uint32_t value;
}pupdr_t;

typedef union
{
	struct
	{
		char IDR0: 2;
		char IDR1: 2;
		char IDR2: 2;
		char IDR3: 2;
		char IDR4: 2;
		char IDR5: 2;
		char IDR6: 2;
		char IDR7: 2;
		char IDR8: 2;
		char IDR9: 2;
		char IDR10: 2;
		char IDR11: 2;
		char IDR12: 2;
		char IDR13: 2;
		char IDR14: 2;
		char IDR15: 2;
	};
	uint32_t value;
}idr_t;

typedef union
{
	struct
	{
		char ODR0: 2;
		char ODR1: 2;
		char ODR2: 2;
		char ODR3: 2;
		char ODR4: 2;
		char ODR5: 2;
		char ODR6: 2;
		char ODR7: 2;
		char ODR8: 2;
		char ODR9: 2;
		char ODR10: 2;
		char ODR11: 2;
		char ODR12: 2;
		char ODR13: 2;
		char ODR14: 2;
		char ODR15: 2;
	};
	uint32_t value;
}odr_t;

typedef union
{
	struct
	{
		char BS0_1 : 2;
		char BS2_3 : 2;
		char BS4_5 : 2;
		char BS6_7 : 2;
		char BS8_9 : 2;
		char BS10_11 : 2;
		char BS12_13 : 2;
		char BS14_15 : 2;
		char BR0_1 : 2;
		char BR2_3 : 2;
		char BR4_5 : 2;
		char BR6_7 : 2;
		char BR8_9 : 2;
		char BR10_11 : 2;
		char BR12_13 : 2;
		char BR14_15 : 2;
	};
	uint32_t value;
}bsrr_t;

typedef union
{
	struct
	{
		char LCK0_1: 2;
		char LCK2_3: 2;
		char LCK4_5: 2;
		char LCK6_7: 2;
		char LCK8_9: 2;
		char LCK10_11: 2;
		char LCK12_13: 2;
		char LCK14_15: 2;
		char LCKK : 2;
		char NO0: 2;
		char NO1: 2;
		char NO2: 2;
		char NO3: 2;
		char NO4: 2;
		char NO5: 2;
		char NO6: 2;
	};
}lckr_t;

typedef union
{
	struct
	{
		short AFRL0: 4;
		short AFRL1: 4;
		short AFRL2: 4;
		short AFRL3: 4;
		short AFRL4: 4;
		short AFRL5: 4;
		short AFRL6: 4;
		short AFRL7: 4;
	};
}afrl_t;

typedef union
{
	struct
	{
		short AFRH8: 4;
		short AFRH9: 4;
		short AFRH10: 4;
		short AFRH11: 4;
		short AFRH12: 4;
		short AFRH13: 4;
		short AFRH14: 4;
		short AFRH15: 4;
	};
}afrh_t;


typedef union
{
	moder_t MODER;
	otyper_t OTYPER;
	ospeed_t OSPEEDR;
	pupdr_t	PUPDR;
	idr_t	IDR;
	odr_t	ODR;
	bsrr_t	BSRR;
	lckr_t	LCKR;
	afrl_t	AFRL;
	afrh_t	AFRH;
}gpio_t;

typedef enum
{
	led_off,
	led_on
}state_t;

typedef enum
{
	led_0 = 12,
	led_1,
	led_2,
	led_3
}led_num_t;

void Gpio_Init();
void ctro_led(led_num_t Led_num, state_t State);
char button();

