/*
 * HL298.c
 *
 *  Created on: Dec 15, 2023
 *      Author: robo1
 */


#include "HL298.h"



void delay(uint32_t delay){
	volatile uint32_t i;

	for (i = 0; i < delay; ++i) {
	        __asm("NOP"); // Pequeño retraso
	    }
}




void Motor_Init() {
    // Habilitar el reloj del puerto A
    SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;

    // Configurar los pines de control como GPIO
    PORTA->PCR[IN1_PIN] = PORT_PCR_MUX(1);
    PORTA->PCR[IN2_PIN] = PORT_PCR_MUX(1);
    PORTA->PCR[ENA_PIN] = PORT_PCR_MUX(1);

    // Configurar los pines de control como salida
    GPIOA->PDDR |= (1 << IN1_PIN) | (1 << IN2_PIN) | (1 << ENA_PIN);

    // Inicializar el motor con dirección hacia adelante y velocidad máxima
    GPIOA->PDOR |= (1 << IN1_PIN); // IN1 High
    GPIOA->PDOR &= ~(1 << IN2_PIN); // IN2 Low
    GPIOA->PDOR |= (1 << ENA_PIN); // ENA High (para habilitar la velocidad)
}


void Motor_Speed(uint8_t speed) {
    // Controlar la velocidad del motor usando PWM en el pin ENA
    // Configurar el valor de PWM para controlar la velocidad
    TPM0->CONTROLS[3].CnV = (speed * 100) - 1; // Ajustar según la velocidad deseada
}



