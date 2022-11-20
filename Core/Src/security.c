#include "security.h"

int set_random_session_security_code(char * session_security_code, size_t session_security_code_length)
{
	uint8_t repetitions[16];
	memset(repetitions, 0, sizeof(repetitions));
	for (uint8_t idx = 0; idx < 8; idx++)
	{
		uint8_t random_number = rand()%16;
		while (repetitions[random_number] == 1)
		{
			random_number = rand()%16;
		}
		repetitions[random_number] = 1;
		session_security_code[idx] = random_number+65;
	}
	return 0;
}
