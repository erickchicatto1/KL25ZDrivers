################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/app.config.c \
../drivers/bitmap_array.c \
../drivers/fsl_adc16.c \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_flash.c \
../drivers/fsl_gpio.c \
../drivers/fsl_i2c.c \
../drivers/fsl_lpsci.c \
../drivers/fsl_smc.c \
../drivers/fsl_tpm.c \
../drivers/fsl_uart.c \
../drivers/i2c.c \
../drivers/i2c_comm.c 

C_DEPS += \
./drivers/app.config.d \
./drivers/bitmap_array.d \
./drivers/fsl_adc16.d \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_flash.d \
./drivers/fsl_gpio.d \
./drivers/fsl_i2c.d \
./drivers/fsl_lpsci.d \
./drivers/fsl_smc.d \
./drivers/fsl_tpm.d \
./drivers/fsl_uart.d \
./drivers/i2c.d \
./drivers/i2c_comm.d 

OBJS += \
./drivers/app.config.o \
./drivers/bitmap_array.o \
./drivers/fsl_adc16.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_flash.o \
./drivers/fsl_gpio.o \
./drivers/fsl_i2c.o \
./drivers/fsl_lpsci.o \
./drivers/fsl_smc.o \
./drivers/fsl_tpm.o \
./drivers/fsl_uart.o \
./drivers/i2c.o \
./drivers/i2c_comm.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL25Z128VLK4_cm0plus -DCPU_MKL25Z128VLK4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DNDEBUG -D__REDLIB__ -I"C:\Users\robo1\Documents\MCUXpressoIDE_11.8.1_1197\workspace\MKL25Z4_Project01\board" -I"C:\Users\robo1\Documents\MCUXpressoIDE_11.8.1_1197\workspace\MKL25Z4_Project01\source" -I"C:\Users\robo1\Documents\MCUXpressoIDE_11.8.1_1197\workspace\MKL25Z4_Project01" -I"C:\Users\robo1\Documents\MCUXpressoIDE_11.8.1_1197\workspace\MKL25Z4_Project01\drivers" -I"C:\Users\robo1\Documents\MCUXpressoIDE_11.8.1_1197\workspace\MKL25Z4_Project01\CMSIS" -I"C:\Users\robo1\Documents\MCUXpressoIDE_11.8.1_1197\workspace\MKL25Z4_Project01\utilities" -I"C:\Users\robo1\Documents\MCUXpressoIDE_11.8.1_1197\workspace\MKL25Z4_Project01\startup" -Os -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-drivers

clean-drivers:
	-$(RM) ./drivers/app.config.d ./drivers/app.config.o ./drivers/bitmap_array.d ./drivers/bitmap_array.o ./drivers/fsl_adc16.d ./drivers/fsl_adc16.o ./drivers/fsl_clock.d ./drivers/fsl_clock.o ./drivers/fsl_common.d ./drivers/fsl_common.o ./drivers/fsl_flash.d ./drivers/fsl_flash.o ./drivers/fsl_gpio.d ./drivers/fsl_gpio.o ./drivers/fsl_i2c.d ./drivers/fsl_i2c.o ./drivers/fsl_lpsci.d ./drivers/fsl_lpsci.o ./drivers/fsl_smc.d ./drivers/fsl_smc.o ./drivers/fsl_tpm.d ./drivers/fsl_tpm.o ./drivers/fsl_uart.d ./drivers/fsl_uart.o ./drivers/i2c.d ./drivers/i2c.o ./drivers/i2c_comm.d ./drivers/i2c_comm.o

.PHONY: clean-drivers

