#include "main.h"

/**
 * _isdigit - function that prints digits as characters
 *
 * @c: character to be printed
 *
 * Return: 1 if successful and 0 if not
 */

int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
