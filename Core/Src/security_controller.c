#include "security_controller.h"

//int set_random_session_security_code(char * session_security_code, uint16_t session_security_code_length)
//{
//	uint8_t repetitions[16];
//	memset(repetitions, 0, sizeof(repetitions));
//	for (uint8_t idx = 0; idx < session_security_code_length; idx++)
//	{
//		uint8_t random_number = rand()%16;
//		while (repetitions[random_number] == 1)
//		{
//			random_number = rand()%16;
//		}
//		repetitions[random_number] = 1;
//		session_security_code[idx] = random_number+65;
//	}
//	return 0;
//}

int set_random_session_security_code(uint8_t * session_security_code, uint16_t session_security_code_length)
{
	for (uint8_t idx = 0; idx < session_security_code_length; idx++)
	{
//		session_security_code[idx] = rand()%57+65;
		session_security_code[idx] = rand()%255;
	}
	return 0;
}
