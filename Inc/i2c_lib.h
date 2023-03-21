#define I2C_BASE_ADDRESS 0x40005400
#define WHO_AM_I_A  0x0F
#define CTRL_REG1_A 0x20
#define CTRL_REG2_A 0x21
#define CTRL_REG3_A 0x22
#define CTRL_REG4_A 0x23
#define CTRL_REG5_A 0x24
#define CTRL_REG6_A 0x25

#define OUT_X_L_A   0x28
#define OUT_X_H_A   0x29

#define OUT_Y_L_A   0x2A
#define OUT_Y_H_A   0x2B

#define OUT_Z_L_A   0x2C
#define OUT_Z_H_A   0x2D


void I2C_Init();
void Read_I2C(uint8_t addr, uint8_t* pData);