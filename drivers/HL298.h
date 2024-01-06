/*
 * HL298.h
 *
 *  Created on: Dec 15, 2023
 *      Author: robo1
 */

#ifndef HL298_H_
#define HL298_H_


#include "MKL25Z4.h"

#define IN1_PIN			0
#define IN2_PIN 		1
#define ENA_PIN			5


void delay(uint32_t delay);

void Motor_Init();

void Motor_Speed(uint8_t speed);











#endif /* HL298_H_ */
