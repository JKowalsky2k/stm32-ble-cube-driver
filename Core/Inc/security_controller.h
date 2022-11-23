#ifndef SECURITY_CONTROLLER_H
#define SECURITY_CONTROLLER_H

#include "main.h"
#include <string.h>
#include <stddef.h>

//int set_random_session_security_code(char * session_security_code, uint16_t session_security_code_length);
int set_random_session_security_code(uint8_t * session_security_code, uint16_t session_security_code_length);

#endif
