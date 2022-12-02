#include "effects_controller.h"

void effect1(uint32_t sleep)
{
	reset_all_shift_registers();
	reset_all_rows();
	set_shift_registers(255, 255);

	HAL_GPIO_WritePin(LAYER1_GPIO_Port, LAYER1_Pin, SET);
	HAL_Delay(sleep);
	reset_all_rows();
	HAL_GPIO_WritePin(LAYER2_GPIO_Port, LAYER2_Pin, SET);
	HAL_Delay(sleep);
	reset_all_rows();
	HAL_GPIO_WritePin(LAYER3_GPIO_Port, LAYER3_Pin, SET);
	HAL_Delay(sleep);
	reset_all_rows();
	HAL_GPIO_WritePin(LAYER4_GPIO_Port, LAYER4_Pin, SET);
	HAL_Delay(sleep);
	reset_all_rows();
	HAL_GPIO_WritePin(LAYER3_GPIO_Port, LAYER3_Pin, SET);
	HAL_Delay(sleep);
	reset_all_rows();
	HAL_GPIO_WritePin(LAYER2_GPIO_Port, LAYER2_Pin, SET);
	HAL_Delay(sleep);
	reset_all_rows();
}

void effect2(uint32_t sleep)
{
	uint8_t leds[6][2] = {
			{0, 240},
			{0, 15},
			{240, 0},
			{15, 0},
			{240, 0},
			{0, 15}
	};
	reset_all_shift_registers();

	for (uint8_t idx = 0; idx < 6; idx++)
	{
		reset_all_rows();
		set_shift_registers(leds[idx][0], leds[idx][1]);
		set_all_rows();
		HAL_Delay(sleep);
	}

//	reset_all_rows();
//	set_shift_registers(240, 0);
//	set_all_rows();
//	HAL_Delay(sleep);
//
//	reset_all_rows();
//	set_shift_registers(15, 0);
//	set_all_rows();
//	HAL_Delay(sleep);
//
//	reset_all_rows();
//	set_shift_registers(0, 240);
//	set_all_rows();
//	HAL_Delay(sleep);
//
//	reset_all_rows();
//	set_shift_registers(0, 15);
//	set_all_rows();
//	HAL_Delay(sleep);
}

void effect3(uint32_t sleep)
{
	uint8_t leds[14][2] = {
			{0, 128},
			{0, 72},
			{128, 36},
			{72, 18},
			{36, 1},
			{18, 0},
			{1, 0},
			{8, 0},
			{132, 0},
			{66, 8},
			{33, 132},
			{16, 66},
			{0, 16}
	};
	reset_all_shift_registers();
	set_all_rows();

	for (uint8_t idx = 0; idx < 14; idx++)
	{
		set_shift_registers(leds[idx][0], leds[idx][1]);
		HAL_Delay(sleep);
	}
}

void effect4(uint32_t sleep)
{
	set_shift_registers(255, 255);
	set_all_rows();
}
