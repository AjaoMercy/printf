#include "main.h"

/**
 * print_upper_hexa - function that prints an unsigned number in upper
 *hexadecimal notation
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

int print_upper_hexa(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
