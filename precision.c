#include "main.h"

/**
 * _precision - function that prints precision
 *
 * @format: format string
 * @i: current index
 *
 * @list: parameter
 * Return: precision value, or -1 if no precision value
 */

int _precision(const char *format, int *i, va_list list)
{
	/* a is the current index initialized to *i + 1*/
	int a = *i + 1;
	int precision = -1;

	if (format[a] != '.')
		return (precision);

	precision = 0;

	/*for loop iterating through the format string*/
	for (a += 1; format[a] != '\0'; a++)
	{
		/*if a is a digit, multiply precision by 10 & add value of digit as int*/
		if (_isdigit(format[a]))
		{
			precision *= 10;
			precision += format[a] - '0';
		}
		/*if a is an *, increment precision and set argumnt to next rgument in list*/
		else if (format[a] == '*')
		{
			a++;
			precision = va_arg(list, int);
			break;
		}
		/*if a is neither digit nor *, break the loop*/
		else
			break;
	}
	*i = a - 1;

	return (precision);
}
