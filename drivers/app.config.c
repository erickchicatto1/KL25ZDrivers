/*
 * app.config.c
 *
 *  Created on: Jan 5, 2024
 *      Author: robo1
 */


#include "app_config.h"


/**********************************************************************************************************************
* Global variable section
*********************************************************************************************************************/
volatile uint32_t g_systickCounter;

/**********************************************************************************************************************
* Global function definition section
*********************************************************************************************************************/

/*******************************************************************************
 * @fn         exampleFunciton
 *
 * @brief      example brief description
 *
 * @param[out]  struct exampleStruct *td: structure of output data
 *
 * @param[in]  int32_t exampleIn: input example
 *
 * @return     uint32_t: return values
 *
******************************************************************************/

void SysTick_Handler(void){

	if(g_systickCounter != 0U){
		g_systickCounter--;
	}

}

void SysTick_DelayTicks(uint32_t n) {
	g_systickCounter = n;

	while(g_systickCounter != 0U){

	}

}



















