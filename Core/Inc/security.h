#ifndef SECURITY_H
#define SECURITY_H

#include "main.h"
#include <string.h>
#include <stddef.h>

int set_random_session_security_code(char * session_security_code, size_t session_security_code_length);

#endif
