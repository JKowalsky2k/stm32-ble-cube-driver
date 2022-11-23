#include "shift_register_controller.h"

void set_registers(uint8_t data1, uint8_t data2)
{
	HAL_GPIO_WritePin(SS_GPIO_Port, SS_Pin, RESET);
	HAL_SPI_Transmit(&hspi1, &data2, 1, 1);
	HAL_SPI_Transmit(&hspi1, &data1, 1, 1);
	HAL_GPIO_WritePin(SS_GPIO_Port, SS_Pin, SET);
}

void reset_all_registers()
{
	set_registers(0, 0);
}

