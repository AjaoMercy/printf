#include "main.h"

/**
 * _width - Calculates the width for printing
 *
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */

int _width(const char *format, int *i, va_list list)
{
	/*a refers to current index*/
	int a;
	int width = 0;

	/*the for loop runs through the current index*/
	/*if statement checks if the character is a digit*/
	/*else if statement checks if the current character is an asterick*/
	for (a = *i + 1; format[a] != '\0'; a++)
	{
		if (_isdigit(format[a]))
		{
			width *= 10;
			width += format[a] - '0';
		}
		else if (format[a] == '*')
		{
			a++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	/*This line assigns the value of a - 1 to *i */
	*i = a - 1;

	return (width);
}
