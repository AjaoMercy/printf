#include "main.h"

/**
 * handle_write_char - Prints a char to output buffer
 *
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */

int handle_write_char(char c, char buffer[], int flags, int width,
	int precision, int size)
{
	/* char is stored at left and paddind at buffer's right */
	int a = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	/*character to print is stored in buffer at index a, & index is incremented*/
	buffer[a++] = c;
	buffer[a] = '\0';

	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (a = 0; a < width - 1; a++)
			buffer[BUFFER_SIZE - a - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFFER_SIZE - a - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - a - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
