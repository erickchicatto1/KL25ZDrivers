################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/GP2Y10.c \
../source/HL298.c \
../source/MKL25Z4_Project01.c \
../source/mtb.c \
../source/semihost_hardfault.c \
../source/ssd1306.c 

C_DEPS += \
./source/GP2Y10.d \
./source/HL298.d \
./source/MKL25Z4_Project01.d \
./source/mtb.d \
./source/semihost_hardfault.d \
./source/ssd1306.d 

OBJS += \
./source/GP2Y10.o \
./source/HL298.o \
./source/MKL25Z4_Project01.o \
./source/mtb.o \
./source/semihost_hardfault.o \
./source/ssd1306.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL25Z128VLK4_cm0plus -DCPU_MKL25Z128VLK4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DNDEBUG -D__REDLIB__ -I"C:\Users\robo1\Documents\MCUXpressoIDE_11.8.1_1197\workspace\MKL25Z4_Project01\board" -I"C:\Users\robo1\Documents\MCUXpressoIDE_11.8.1_1197\workspace\MKL25Z4_Project01\source" -I"C:\Users\robo1\Documents\MCUXpressoIDE_11.8.1_1197\workspace\MKL25Z4_Project01" -I"C:\Users\robo1\Documents\MCUXpressoIDE_11.8.1_1197\workspace\MKL25Z4_Project01\drivers" -I"C:\Users\robo1\Documents\MCUXpressoIDE_11.8.1_1197\workspace\MKL25Z4_Project01\CMSIS" -I"C:\Users\robo1\Documents\MCUXpressoIDE_11.8.1_1197\workspace\MKL25Z4_Project01\utilities" -I"C:\Users\robo1\Documents\MCUXpressoIDE_11.8.1_1197\workspace\MKL25Z4_Project01\startup" -Os -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/GP2Y10.d ./source/GP2Y10.o ./source/HL298.d ./source/HL298.o ./source/MKL25Z4_Project01.d ./source/MKL25Z4_Project01.o ./source/mtb.d ./source/mtb.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o ./source/ssd1306.d ./source/ssd1306.o

.PHONY: clean-source

