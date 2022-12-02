#include "command_controller.h"

int get_mode_from_command(const char* command_buffer)
{
	char command1[] = "M1";
	if (strcmp(command_buffer, command1) == 0)
	{
		return 1;
	}
	char command2[] = "M2";
	if (strcmp(command_buffer, command2) == 0)
	{
		return 2;
	}
	return 0;
}
