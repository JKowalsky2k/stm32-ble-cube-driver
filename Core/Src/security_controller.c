#include "security_controller.h"

int set_random_session_security_code(uint8_t * session_security_code, uint16_t session_security_code_length)
{
	for (uint8_t idx = 0; idx < session_security_code_length; idx++)
	{
		session_security_code[idx] = rand()%57+65;
//		session_security_code[idx] = rand()%255;
	}
	return 0;
}

int check_security_code(const char * uart_msg_security_code, const char* session_security_code)
{
	if (strcmp(uart_msg_security_code, session_security_code) == 0)
	{
		return 1;
	}
	return 0;
}

int check_data_crc(	const char * uart_msg_security_code,
					const char * uart_msg_command,
					const char * uart_msg_data,
					const char * uart_msg_crc)
{
	uint32_t sum = 0;
	for (int idx = 0; idx < 2; idx++)
	{
		sum += uart_msg_security_code[idx];
	}
	for (int idx = 0; idx < 2; idx++)
	{
		sum += uart_msg_command[idx];
	}
	for (int idx = 0; idx < 10; idx++)
	{
		sum += uart_msg_data[idx];
	}
	if (sum == atoi(uart_msg_crc))
	{
		return 1;
	}
	return 0;
}
