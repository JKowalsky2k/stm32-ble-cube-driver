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
