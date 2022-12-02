#include "command_controller.h"

int get_mode_from_command(const char* command_buffer)
{
	char command1[] = "M1";
	if (0 == strcmp(command_buffer, command1))
	{
		return 1;
	}
	char command2[] = "M2";
	if (0 == strcmp(command_buffer, command2))
	{
		return 2;
	}
	char command3[] = "M3";
	if (0 == strcmp(command_buffer, command3))
	{
		return 3;
	}
	char command4[] = "M4";
	if (0 == strcmp(command_buffer, command4))
	{
		return 4;
	}
	return 0;
}
