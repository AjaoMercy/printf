#include "main.h"

/**
 * print_buffer - Prints the contents of the buffer to stdout if the buffer
 *			exist and resets it to zero
 *
 * @buffer: Array of chars
 * @buffer_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buffer_ind)
{
	if (*buffer_ind > 0)
		write(1, &buffer[0], *buffer_ind);

	*buffer_ind = 0;
}

/* a buffer is a temporary container that holds data befoer it is processed*/
/*and sent to its destination. if the content of the buffer is greater than*/
/*zero, it prints everything and resets it to zero*/
