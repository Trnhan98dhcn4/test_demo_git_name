All:
	arm-none-eabi-gcc -std=gnu11 -mcpu=cortex-m4 -c main.c -o build/main.o 

	arm-none-eabi-gcc -std=gnu11 -mcpu=cortex-m4 -c Src/rcc_lib.c -o build/rcc_lib.o 
	arm-none-eabi-gcc -std=gnu11 -mcpu=cortex-m4 -c Src/gpio_lib.c -o build/gpio_lib.o
	arm-none-eabi-gcc -std=gnu11 -mcpu=cortex-m4 -c Src/systick_lib.c -o build/systick_lib.o
	arm-none-eabi-gcc -std=gnu11 -mcpu=cortex-m4 -c Src/vttb_lib.c -o build/vttb_lib.o
	arm-none-eabi-gcc -std=gnu11 -mcpu=cortex-m4 -c Src/exti_lib.c -o build/exti_lib.o
	arm-none-eabi-gcc -std=gnu11 -mcpu=cortex-m4 -c Src/pwm_lib.c -o build/pwm_lib.o
	arm-none-eabi-gcc -std=gnu11 -mcpu=cortex-m4 -c Src/i2c_lib.c -o build/i2c_lib.o

	arm-none-eabi-gcc -mcpu=cortex-m4 -c -x assembler-with-cpp startup_stm32f411vetx.s -o build/startup.o
	arm-none-eabi-gcc -mcpu=cortex-m4 build/i2c_lib.o build/pwm_lib.o build/exti_lib.o build/rcc_lib.o build/main.o build/startup.o build/gpio_lib.o build/systick_lib.o build/vttb_lib.o -T"STM32F411VETX_FLASH.ld" -Wl,-Map="build/mapfile.map" -Wl,--gc-sections -static -o build/program.elf
	arm-none-eabi-objcopy -O binary build/program.elf build/program.bin