#ifndef SHIFT_REGISTER_CONTROLLER_H
#define SHIFT_REGISTER_CONTROLLER_H

#include <spi.h>
#include <gpio.h>

void set_registers(uint8_t data1, uint8_t data2);
void reset_all_registers();

#endif
