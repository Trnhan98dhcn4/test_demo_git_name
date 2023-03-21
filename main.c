#include <stdint.h>
#include "Inc\rcc_lib.h"
#include "Inc\gpio_lib.h"
#include "Inc\systick_lib.h"
#include "Inc\vttb_lib.h"
#include "Inc\exti_lib.h"
#include "Inc\pwm_lib.h"
#include "Inc\i2c_lib.h"



void SystemInit()
{
	
}

void main()
{
	RCC_LSE_Init();
	RCC_PLL_Init();
	//Gpio_Init();
	Delay_Init();
	//EXTI0_Init();
	vttb_init();
	PWM_Output_Compare();
	I2C_Init();

	
	
	while (1)
	{
		for(int i = 0; i < 99; i++)
		{
			Modify_PWM(i);
			delay_ms(1000);
		}
	}
}