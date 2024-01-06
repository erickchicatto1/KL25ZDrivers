/*
 * GP2Y10.h
 *
 *  Created on: Dec 15, 2023
 *      Author: robo1
 */

#ifndef GP2Y10_H_
#define GP2Y10_H_

#include "fsl_adc16.h"
#include "fsl_clock.h"
#include "fsl_port.h"


#define ADC_BASE ADC0
#define ADC_CHANNEL 0 // Canal ADC que estás utilizando
#define VREF_BRD 3300 // Tensión de referencia en mV para la KL25Z



void ADC_Init();
uint16_t ADC_Read();
float ConvertToVoltage(uint16_t adcValue);
float GetDustConcentration(float voltage) ;


#endif /* GP2Y10_H_ */
