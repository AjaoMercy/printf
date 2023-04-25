#include "main.h"

/**
 * _size - checks size of argument to be printed
 *
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: size.
 */

int _size(const char *format, int *i)
{
	/* a = current index in the format string plus one*/
	int a = *i + 1;
	/*size initialized to and used to store size value*/
	int size = 0;

	/*S_LONG is defined by 2, S_SHORT is defined by 1*/
	if (format[a] == 'l')
		size = S_LONG;
	else if (format[a] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = a - 1;
	else
		*i = a;

	return (size);
}
