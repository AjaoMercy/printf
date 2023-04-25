#include "main.h"

/**
 * _printf - a function that works like the original printf
 *
 * @format: the character pointer
 * Return: Printed output
 */

int _printf(const char *format, ...)
{
	int a, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buffer_ind = 0;
	va_list arguments;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(arguments, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			/*if not a format specifier, store in buffer and increment buffer index */
			buffer[buffer_ind++] = format[a];
			if (buffer_ind == BUFFER_SIZE)
				print_buffer(buffer, &buffer_ind);
			printed_chars++;
		}
		else
		{
			/* if a format specifier is found, process the specifier and the argument */
			print_buffer(buffer, &buffer_ind);
			flags = _flags(format, &a);
			width = _width(format, &a, arguments);
			precision = _precision(format, &a, arguments);
			size = _size(format, &a);
			++a;
			printed = print_arg_type(format, &a, arguments, buffer, flags,
				width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buffer_ind);
	va_end(arguments);
	return (printed_chars);
}
