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
}

void effect2(uint32_t sleep)
{
	reset_all_shift_registers();

	reset_all_rows();
	set_shift_registers(240, 0);
	set_all_rows();
	HAL_Delay(sleep);

	reset_all_rows();
	set_shift_registers(15, 0);
	set_all_rows();
	HAL_Delay(sleep);

	reset_all_rows();
	set_shift_registers(0, 240);
	set_all_rows();
	HAL_Delay(sleep);

	reset_all_rows();
	set_shift_registers(0, 15);
	set_all_rows();
	HAL_Delay(sleep);

}
