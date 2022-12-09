#ifndef LED_CUBE_CONTROLLER_H
#define LED_CUBE_CONTROLLER_H

#include <spi.h>
#include <gpio.h>

void set_shift_registers(uint8_t data1, uint8_t data2);
void reset_all_shift_registers(void);
void reset_all_rows(void);
void set_all_rows(void);

#endif
