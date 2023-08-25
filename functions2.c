#include "main.h"

/**
 * flush - Flushes Buffer
 * @buffer: Buffer
 * @idx: Pointer to index variable
 *
 * Return: Nothing
 */
void flush(char buffer[], int *idx)
{
	int i;

	for (i = 0; i <= *idx; i++)
		write(1, &buffer[i], 1);
	*idx = 0;
}

/**
 * buffer_insert - Insert into buffer
 * @c: Char to insert
 * @buffer: Buffer
 * @idx: Pointer to index variable
 *
 * Return: Nothing
 */
void buffer_insert(char c, char buffer[], int *idx)
{
	buffer[*idx] = c;
	if (*idx + 1 == BUFF_SIZE)
		flush(buffer, idx);
	(*idx)++;
}
