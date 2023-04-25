#include "main.h"

/**
 * print_octa - function that prints an unsigned number in octal notation
 *
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */

int print_octa(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	/*declaring variables*/
	int a = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[a--] = '0';

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
