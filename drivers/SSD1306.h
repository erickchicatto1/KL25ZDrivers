/*
 * SSD1306.h
 *
 *  Created on: Dec 22, 2023
 *      Author: robo1
 */

#ifndef SSD1306_H_
#define SSD1306_H_

#include <stdint.h>
#include <fsl_common.h>
#include <bitmap_array.h>
#define SSD1306_ADDR	0x3C

typedef struct {
	uint8_t mux_ratio_addr,
	mux_ratio_val,
	disp_offset_addr,
	disp_offset_val,
	segment_remap,
	output_scan_dir,
	hardware_cfg_addr,
	hardware_cfg_val,
	contrast_ctrl_addr,
	contrast_ctrl_val,
	disable_disp,
	normal_disp,
	osc_freq_addr,
	osc_freq_val,
	charge_regulator_addr,
	charge_regulator_val,
	display_on;
}ssd1306_cfg_t;


typedef struct {

	uint8_t addr_mode_addr,
			addr_mode_set,
			set_column_addr,
			set_column_start,
			set_column_end,
			set_page_addr,
			set_page_start,
			set_page_end;
}addr_mode_cfg_t;


//1. Need to init the I2C


//2. To write the commands , this function I created
uint32_t WriteCommands(uint32_t bytes);

// 3. To set bytes/bites
void setBit(uint8_t *byte, uint8_t bitPosition);
void clearBit(uint8_t *byte, uint8_t bitPosition);
void toggleBit(uint8_t *byte, uint8_t bitPosition);
void writeByte(volatile uint8_t *address , uint8_t value);
void readByte(const volatile uint8_t *address);
void readBit(uint8_t byte, uint8_t bitPosition);


/**********************************************************************************************************************
* Function declaration section
*********************************************************************************************************************/
void ssd1306_init(void);
bool transpose(unsigned char * input, int rows,unsigned char * output);
void ssd1306_write(unsigned char * input , uint16_t input_len);





#endif /* SSD1306_H_ */
