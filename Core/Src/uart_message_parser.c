#include "uart_message_parser.h"

#define COMMAND_START_IN_UART_MESSAGE 2
#define DATA_START_IN_UART_MESSAGE 4
#define CRC_START_IN_UART_MESSAGE 14

int set_crc_input_from_uart_message(const char * uart_message_buffer,
									char * destination_buffer,
									size_t destination_buffer_length)
{
	strncpy(destination_buffer, uart_message_buffer, destination_buffer_length);
	destination_buffer[14] = '\0';
	return 0;
}

int set_security_code_from_uart_message(const char * uart_message_buffer,
										char * destination_buffer,
										size_t destination_buffer_length)
{
	strncpy(destination_buffer, uart_message_buffer, destination_buffer_length);
	return 0;
}

int set_command_from_uart_message(	const char * uart_message_buffer,
									char * destination_buffer,
									size_t destination_buffer_length)
{
	strncpy(destination_buffer, uart_message_buffer+COMMAND_START_IN_UART_MESSAGE, destination_buffer_length);
	return 0;
}

int set_data_from_uart_message(	const char * uart_message_buffer,
								char * destination_buffer,
								size_t destination_buffer_length)
{
	strncpy(destination_buffer, uart_message_buffer+DATA_START_IN_UART_MESSAGE, destination_buffer_length);
	return 0;
}

int set_crc_from_uart_message(	const char * uart_message_buffer,
								char * destination_buffer,
								size_t destination_buffer_length)
{
	strncpy(destination_buffer, uart_message_buffer+CRC_START_IN_UART_MESSAGE, destination_buffer_length);
	return 0;
}
