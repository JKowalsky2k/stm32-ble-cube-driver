#include "shift_register_controller.h"

void set_shift_registers(uint8_t data1, uint8_t data2)
{
	HAL_GPIO_WritePin(SS_GPIO_Port, SS_Pin, RESET);
	HAL_SPI_Transmit(&hspi1, &data2, 1, 1);
	HAL_SPI_Transmit(&hspi1, &data1, 1, 1);
	HAL_GPIO_WritePin(SS_GPIO_Port, SS_Pin, SET);
}

void reset_all_shift_registers(void)
{
	set_shift_registers(0, 0);
}

void reset_all_rows(void)
{
	HAL_GPIO_WritePin(LAYER1_GPIO_Port, LAYER1_Pin, RESET);
	HAL_GPIO_WritePin(LAYER2_GPIO_Port, LAYER2_Pin, RESET);
	HAL_GPIO_WritePin(LAYER3_GPIO_Port, LAYER3_Pin, RESET);
	HAL_GPIO_WritePin(LAYER4_GPIO_Port, LAYER4_Pin, RESET);
}

void set_all_rows(void)
{
	HAL_GPIO_WritePin(LAYER1_GPIO_Port, LAYER1_Pin, SET);
	HAL_GPIO_WritePin(LAYER2_GPIO_Port, LAYER2_Pin, SET);
	HAL_GPIO_WritePin(LAYER3_GPIO_Port, LAYER3_Pin, SET);
	HAL_GPIO_WritePin(LAYER4_GPIO_Port, LAYER4_Pin, SET);
}
