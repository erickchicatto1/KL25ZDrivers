/*
 * i2c.h
 *
 *  Created on: Dec 23, 2023
 *      Author: robo1
 */

#ifndef I2C_H_
#define I2C_H_

#include "MKL25Z4.h"
#include "stdbool.h"

//https://github.com/evandro-teixeira/frdm-kl25z-i2c/blob/master/i2c.h

#define ALT0		0
#define ALT1		1
#define ALT2		2
#define ALT3		3
#define MULT0		0
#define MULT1		1
#define MULT2		2
#define I2C_WRITE	0 //Master write
#define I2C_READ	1 //Master read


void i2c_init2();
void i2c_DisableAck();
void i2c_EnableAck();
void i2c_RepeatedStart();
void i2c_EnterRxMode();
void i2c_Start();
void i2c_Stop();
void i2c_WriteByte(uint8_t data);
uint8_t i2c_ReadByte();
















#endif /* I2C_H_ */
