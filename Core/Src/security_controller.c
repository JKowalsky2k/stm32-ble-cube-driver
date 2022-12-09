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

int check_data_crc(const char * uart_msg_crc_input, const char * uart_msg_crc)
{
	uint8_t *result = md5String(uart_msg_crc_input);
	char tmp[2];
	uint8_t idx = 0;
	char converted_crc[32];
	for(unsigned int i = 0; i < 16; ++i){
		sprintf(tmp ,"%02x", result[i]);
		converted_crc[idx] = tmp[0];
		converted_crc[idx+1] = tmp[1];
		idx += 2;
		printf("%s", tmp);
	}
	if (converted_crc[3] 	== uart_msg_crc[0] &&
		converted_crc[5] 	== uart_msg_crc[1] &&
		converted_crc[11] 	== uart_msg_crc[2] &&
		converted_crc[21] 	== uart_msg_crc[3] &&
		converted_crc[25] 	== uart_msg_crc[4] &&
		converted_crc[30] 	== uart_msg_crc[5])
	{
		return 1;
	}
	return 0;
}
