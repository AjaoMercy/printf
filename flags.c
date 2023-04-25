#include "main.h"

/**
 * _flags - extracts flag character and prints their bit values
 *
 * @format: formated string to print arguments from
 * @i: argument to be printed
 *
 * Return: values
 */

int _flags(const char *format, int *i)
{
	int a, b;
	int flags = 0;
	/*flag characters*/
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	/*array of corresponding bit value of flag characters*/
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (b = *i + 1; format[b] != '\0'; b++)
	{
		for (a = 0; FLAGS_CH[a] != '\0'; a++)
			if (format[b] == FLAGS_CH[a])
			{
				flags |= FLAGS_ARR[a];
				break;
			}

		if (FLAGS_CH[a] == 0)
			break;
	}
	*i = b - 1;

	return (flags);
}
/*The loop starts at the character immediately following the*/
/*character in the format string and continues until the end of the string*/

/*The inner loop searches through the FLAGS_CH array for a character*/
/*that matches the current character in the format string. If a match*/
/*is found, the corresponding bit value from FLAGS_ARR is added to the*/
/*flags variable using the bitwise OR operator (|).*/

/*If no match is found in FLAGS_CH, the inner loop is terminated and the*/
/*outer loop continues to the next character in the format string.*/

/*Finally, the value of b is assigned to *i (which is a pointer to an*/
/*integer) and then decremented by 1 before being returned as the*/
/*function's output*/
