#include "main.h"

/**
 * write_ptr - Write a memory address
 *
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */

int write_ptr(char buffer[], int ind, int length, int width, int flags,
	char padd, char extra_c, int padd_start)
{
	/*variables declaration*/
	int a;

	if (width > length)
	{
		for (a = 3; a < width - length + 3; a++)
			buffer[a] = padd;
		buffer[a] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], a - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], a - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], a - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFFER_SIZE - ind - 1));
}

/*If the width is greater than the length of the number, it enters a loop to*/
/*fill the buffer with the padding character, starting at index 3 (to account*/
/*for "0x" characters). The loop runs until the padding extends past the end*/
/*of the number. Then, the null terminator is added to the end of the buffer.*/

/*If the minus flag is set and the padding is a space, it assigns the extra*/
/*character to the left of the buffer, then writes the buffer to standard*/
/*output. If the minus flag is not set and the padding is a space, it*/
/*assigns the extra character to the left of the buffer, then writes the*/
/*buffer to standard output. If the minus flag is not set and the padding is*/
/*a zero, it assigns the extra character to the left of the padding, adds*/
/*"0x" to the start of the buffer, and writes the buffer to standard output.*/

/*Adds "0x" and the extra character (if present) to the start of the buffer,*/
/*then writes the buffer to standard output.*/
