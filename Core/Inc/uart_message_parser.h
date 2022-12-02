#ifndef UART_MESSAGE_PARSER_H
#define UART_MESSAGE_PARSER_H

#include <string.h>
#include <stddef.h>

int set_security_code_from_uart_message(	const char * uart_message_buffer,
										char * destination_buffer,
										size_t destination_buffer_length);

int set_command_from_uart_message(	const char * uart_message_buffer,
									char * destination_buffer,
									size_t destination_buffer_length);

int set_data_from_uart_message(	const char * uart_message_buffer,
								char * destination_buffer,
								size_t destination_buffer_length);

int set_crc_from_uart_message(	const char * uart_message_buffer,
								char * destination_buffer,
								size_t destination_buffer_length);

#endif
