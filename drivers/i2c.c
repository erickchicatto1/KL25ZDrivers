/*
 * i2c.c
 *
 *  Created on: Dec 23, 2023
 *      Author: robo1
 */



#include "i2c.h"

#define I2C_BAUD_RATE 100000

void i2c_init2(){

 SIM->SCGC4 |= SIM_SCGC4_I2C0_MASK;


  PORTB->PCR[0] = PORT_PCR_MUX(2); //
  PORTB->PCR[1] = PORT_PCR_MUX(2); //

  I2C0->F = I2C_F_MULT(0) | I2C_F_ICR((SystemCoreClock / 2) / I2C_BAUD_RATE);

  I2C0->C1 |= I2C_C1_IICEN_MASK;
}

I2C_Type *i2c;

void i2c_DisableAck() {

	i2c->C1 |= I2C_C1_TXAK_MASK;
}

void i2c_EnableAck(){
	i2c->C1 &= ~I2C_C1_TXAK_MASK;
}

void i2c_RepeatedStart(){
	i2c->C1 |= I2C_C1_RSTA_MASK;
}

void i2c_EnterRxMode(){
	i2c->C1 &= ~I2C_C1_TX_MASK;
}

void i2c_Start(){
	i2c->C1 |= I2C_C1_TX_MASK;
	i2c->C1 |= I2C_C1_MST_MASK;
}

void i2c_Stop(){
	i2c->C1 &= ~I2C_C1_MST_MASK;
	i2c->C1 &= ~I2C_C1_TX_MASK;
}

void i2c_WriteByte(uint8_t data) {
	i2c->D=(uint8_t)data;
}


uint8_t i2c_ReadByte(){
	return (uint8_t)(i2c->D);
}

