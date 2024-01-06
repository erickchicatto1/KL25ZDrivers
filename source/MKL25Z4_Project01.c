#include "MKL25Z4.h"
#include "SSD1306.h"

#include <stdio.h>


#define TRIG_PIN 4  // PTE4
#define ECHO_PIN 5  // PTE5

float distance=0;

void delay_us(uint32_t us) {
    volatile uint32_t cycles = (us * (SystemCoreClock / 1000000)) / 6;
    while (cycles--);
}

void init_GPIO(void) {
    SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;

    PORTE->PCR[TRIG_PIN] &= ~PORT_PCR_MUX_MASK;
    PORTE->PCR[TRIG_PIN] |= PORT_PCR_MUX(1);

    PORTE->PCR[ECHO_PIN] &= ~PORT_PCR_MUX_MASK;
    PORTE->PCR[ECHO_PIN] |= PORT_PCR_MUX(1);

    GPIOE->PDDR |= (1 << TRIG_PIN);
    GPIOE->PDDR &= ~(1 << ECHO_PIN);
}

float measure_distance(void) {

    GPIOE->PSOR |= (1 << TRIG_PIN);
    delay_us(10);
    GPIOE->PCOR |= (1 << TRIG_PIN);


    while (!(GPIOE->PDIR & (1 << ECHO_PIN)));


    uint32_t start_time = 0;
    while (GPIOE->PDIR & (1 << ECHO_PIN)) {
        start_time++;
    }


    distance = (float)(start_time * 0.017);

    return distance;
}

void Stadistics(void){


	 float DistanceArray[10]={0};

	 for(volatile uint8_t i=0;i<10;i++){
	       distance = measure_distance();
	       DistanceArray[i] = distance;
	 }


	 for(volatile uint8_t i=0;i<10;i++){

	   float Max = DistanceArray[0];
	   printf("%d \n", DistanceArray[i]);

	   if(DistanceArray[i]>Max){
	    		Max = DistanceArray[i];
	    }
	   }
}


int main(void) {

    SystemCoreClockUpdate();
    init_GPIO();

    //For the i2c
    WriteCommands(0b011110);


}
