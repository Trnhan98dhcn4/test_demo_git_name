#include <stdint.h>
#include "../Inc/i2c_lib.h"
#include "../Inc/gpio_lib.h"
#include "../Inc/rcc_lib.h"

void I2C_Init()
{
    uint32_t* RCC_AHB1ENR = (uint32_t*)(RCC_BASE_ADDRESS + 0x30);
    *RCC_AHB1ENR |= (0b1 << 1);                                         //enable RCC GPIOB

    gpio_t* PortB_Moder = (gpio_t*)(PORTB_BASE_ADDR + 0x00);
    PortB_Moder->MODER.MODER8 = ALTERNATE_FUNCTION_MODE;
    PortB_Moder->MODER.MODER9 = ALTERNATE_FUNCTION_MODE;

    gpio_t* PortB_AFRH = (gpio_t*)(PORTB_BASE_ADDR + 0x24);
    PortB_AFRH->AFRH.AFRH8 = AF4;
    PortB_AFRH->AFRH.AFRH9 = AF4;

    uint32_t* RCC_APB1ENR = (uint32_t*)(RCC_BASE_ADDRESS + 0x40);
    *RCC_APB1ENR |= (0b1 << 21);                                        // enable RCC I2C

    uint32_t* CR1 = (uint32_t*)(I2C_BASE_ADDRESS + 0x00);
    *CR1 &= ~(0b1 << 0);
    uint32_t* CR2 = (uint32_t*)(I2C_BASE_ADDRESS + 0x04);
    *CR2 |= (16 << 0);
    uint32_t* CCR = (uint32_t*)(I2C_BASE_ADDRESS + 0x1C);
    *CCR = 80;                                                          // set 200Hz -> RCC = 16MHz / 80 = 200Hz
    
    *CR1 |= (0b1 << 0);
}

void Read_I2C(uint8_t addr, uint8_t* pData)
{
    uint32_t* CR1 = (uint32_t*)(I2C_BASE_ADDRESS + 0x00);
    uint32_t* DR = (uint32_t*)(I2C_BASE_ADDRESS + 0x10);
    uint32_t* SR1 = (uint32_t*)(I2C_BASE_ADDRESS + 0x14);
    uint32_t* SR2 = (uint32_t*)(I2C_BASE_ADDRESS + 0x18);

    uint8_t id_senser = (0b0011001 << 1);               // id_sensor

    while(((*SR2 >> 1) & 1) == 1);                      // check bit BYS

    *CR1 |= (0b1 << 8);                                 // set bit start
    while(((*SR1 >> 0) & 1) != 1);                      
    *DR = id_senser | 0;                                // set bit write 
    while(((*SR1 >> 1) & 1) != 1);
    uint8_t temp = *SR2;                        
    (void)temp;
    
    *DR = addr;                                         // write in Data
    while(((*SR1 >> 2) & 1) != 1);
    while(((*SR1 >> 10) & 1) == 1);

    *CR1 |= (0b1 << 8);                                 // set bit Start
    while(((*SR1 >> 0) & 1) != 1);

    *DR = id_senser | 1;                                // set bit read vao
    while(((*SR1 >> 1) & 1) != 1);
    temp = *SR2;
    (void)temp;

    while(((*SR1 >> 6) & 1) != 1);
    uint8_t data = *DR;
    (void)data;

    *CR1 |= (0b1 << 9);

    *pData = *DR;
}