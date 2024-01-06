/*
 * ssd1306.c
 *
 *  Created on: Dec 22, 2023
 *      Author: robo1
 */


#include "SSD1306.h"
#include "fsl_i2c.h"
#include <stdint.h>


/**********************************************************************************************************************
* Global variable section
*********************************************************************************************************************/
uint8_t CMD_control_byte = 0x00 ;
uint8_t data_control_byte = 0x40 ;



void setBit(uint8_t *byte, uint8_t bitPosition){ //0000 1111 , 3
	*byte |= (1<<bitPosition);  //1<<3    0001 1110 -> 0011 1100 -> 0111 1000
}

void clearBit(uint8_t *byte, uint8_t bitPosition){
	*byte &= ~(1<<bitPosition);
}

void toggleBit(uint8_t *byte, uint8_t bitPosition){
	*byte ^=(1<<bitPosition);
}

void writeByte(volatile uint8_t *address , uint8_t value){
	*address = value;
}
/*
 * void readByte(volatile uint8_t *address){
	return *address;
}
 * */
/*void readBit(uint8_t byte, uint8_t bitPosition){
	return (byte & (1 << bitPosition)) != 0;
}
 *
 *
 * */

//To Do : Make a switch case
uint32_t WriteCommands(uint32_t bytes){

	//1.start condition and init the i2c
	i2c_init();
	i2c_Start();
	//2.Write byte to the slave 0b011110
	i2c_WriteByte(bytes);
	//3.The write mode is established by setting the r/w bit logic to 0
	//4.
	//5.
	if((bytes & 0x0)==0){
		i2c_ReadByte();
	}

}


void ssd1306_write(unsigned char * input , uint16_t input_len){

	status_t result = 1;

	//setting horizontal addressing mode for the input
	uint8_t addr_mode[]={
		0x20,0x00,
		//  setting column start and end address
		0x21,0x00,0x7F,
		//	setting page start and end address
		0x22, 0x00, 0x07
	};

	/**each letter is 8x8. So in one page (containing 8 pixel rows),
	 * we can have 128/8 = 16 characters/letters.
	 * Hence, we have a total of 16*(8 pages) = 128 chars/letters in total
	**/
	//array to be sent to ssd1306
	uint8_t sending_arr[1024] = {0};
	memset(sending_arr,0,1024);

	unsigned char letter[8]={0};
	unsigned char transposed_letter[8]={0};
	int16_t offset = 0;
	//we dont want to evaluate the /0 character at the end
	int16_t arr_offset = 0 ;
	for(int m=0;m<input_len-1;m++){

		if(input[m] != ' '){
			offset = input[m]-calibri_7ptFontInfo.startChar;
			FONT_CHAR_INFO letter_info = calibri_7ptFontInfo.charInfo[offset];
			memcpy(letter, calibri_7ptFontInfo.data+letter_info.offset, 8);
			//transpose this letter
			if(!transpose (letter, 8, transposed_letter)){
				return;
			}
		}

		//add this transposed letter to the sending array
		memcpy(sending_arr + arr_offset, transposed_letter, 8);
		arr_offset += 8;
		memset(letter, 0, 8);
		memset(transposed_letter, 0, 8);

	}

	printf("Configure addressing mode...\n");
	result = i2c_transfer(SSD1306_ADDR, kI2C_Write, CMD_control_byte, addr_mode, sizeof(addr_mode));
	SysTick_DelayTicks(10U);
	printf("Try inputting some data...\n");
	result = i2c_transfer(SSD1306_ADDR, kI2C_Write, data_control_byte, sending_arr, sizeof(sending_arr));




}





















