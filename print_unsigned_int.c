#include "main.h"

/**
 * print_unsigned_int - Prints an unsigned number
 *
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */

int print_unsigned_int(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	/*declaring varibles*/
	/* initializing a counter variable a to the second last index of the buffer.*/
	int a = BUFFER_SIZE - 2;
	/*extracting the next argument from the va_list types & assigning it to num*/
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	/*this sets the last unused index of buffer to '0' & decrements the a by one*/
	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}
	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
