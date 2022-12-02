#ifndef SECURITY_CONTROLLER_H
#define SECURITY_CONTROLLER_H

#include "main.h"
#include <string.h>
#include <stddef.h>

int set_random_session_security_code(uint8_t * session_security_code, uint16_t session_security_code_length);
int check_security_code(const char * uart_msg_security_code, const char* session_security_code);
int check_data_crc(const char * uart_msg_security_code,
						 const char * uart_msg_command,
						 const char * uart_msg_data,
						 const char * uart_msg_crc);

#endif
