#include "main.h"

/**
 * print_r13string - function that print a string in rot13.
 *
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Numbers of chars printed
 */

int print_r13string(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	char a;
	char *str;
	unsigned int b, c;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (b = 0; str[b]; b++)
	{
		for (c = 0; in[c]; c++)
		{
			if (in[c] == str[b])
			{
				a = out[c];
				write(1, &a, 1);
				count++;
				break;
			}
		}
		if (!in[c])
		{
			a = str[b];
			write(1, &a, 1);
			count++;
		}
	}
	return (count);
}
