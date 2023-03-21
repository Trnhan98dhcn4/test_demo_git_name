#include <stdint.h>
#include <string.h>
#include "..\Inc\systick_lib.h"
#include "..\Inc\vttb_lib.h"
#include "..\Inc\exti_lib.h"


void vttb_init()
{
	memcpy((void*)0x20000000, 0, 0x198);// copy vector table size 0 -> 0x198
	uint32_t* VTOR = (uint32_t*)0xe000ed08; // enable vector table
	*VTOR = 0x20000000; //in Ram

	// custom exti0
	 uint32_t* EXTI0_Address_custom = (uint32_t*) 0x20000058;
	 *EXTI0_Address_custom = (uint32_t)EXTI0_Custom_Handler | 1;

	//custom Systick
	uint32_t* Systick_address_Custom = (uint32_t*) 0x2000003C;
	*Systick_address_Custom = (uint32_t)Systick_custom_Handler | 1;

	// custom UART2
	//uint32_t* UART2_address_Custom = (uint32_t*) 0x200000D8;
	//*UART2_address_Custom = (uint32_t)UART2_custom_Handler | 1;
}