/*
 * GP2Y10.c
 *
 *  Created on: Dec 15, 2023
 *      Author: robo1
 */
#include "GP2Y10.h"



void ADC_Init() {
    adc16_config_t adc16ConfigStruct;

    CLOCK_EnableClock(kCLOCK_Adc0);
    CLOCK_EnableClock(kCLOCK_PortB);

    PORT_SetPinMux(PORTB, ADC_CHANNEL, kPORT_PinDisabledOrAnalog);

    ADC16_GetDefaultConfig(&adc16ConfigStruct);
    ADC16_Init(ADC_BASE, &adc16ConfigStruct);
    ADC16_EnableHardwareTrigger(ADC_BASE, false);
    ADC16_DoAutoCalibration(ADC_BASE);
}


uint16_t ADC_Read() {
    adc16_channel_config_t adcChnConfig;

    ADC16_EnableHardwareTrigger(ADC_BASE, false);
    adcChnConfig.channelNumber = ADC_CHANNEL;
    adcChnConfig.enableInterruptOnConversionCompleted = false;
    ADC16_SetChannelConfig(ADC_BASE, 0, &adcChnConfig);

    while (!(kADC16_ChannelConversionDoneFlag & ADC16_GetChannelStatusFlags(ADC_BASE, 0)))
    {
    }

    return ADC16_GetChannelConversionValue(ADC_BASE, 0);
}

float ConvertToVoltage(uint16_t adcValue) {
    return ((float)adcValue * VREF_BRD) / 65535.0f;
}

float GetDustConcentration(float voltage) {
    // Fórmula aproximada para la concentración de polvo
    // Esta relación puede variar según las condiciones ambientales y el sensor
    float dustConcentration = voltage * 0.1f; // Ajusta este valor según la calibración

    return dustConcentration;
}

