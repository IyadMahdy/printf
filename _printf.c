#include "main.h"

/**
 * print_none - For when the format specifier is unknown
 * @c: char
 * @space: Checks space
 * @buffer: Buffer
 * @idx: Pointer to idx variable
 *
 * Return: Number of chars printed
 */
int print_none(char c, int space, char buffer[], int *idx)
{
	char c2, pcnt, spc;
	int count = 2;

	c2 = c;
	pcnt = 37;
	spc = 32;
	buffer_insert(pcnt, buffer, idx);

	if (space)
	{
		buffer_insert(spc, buffer, idx);
		count++;
	}
	buffer_insert(c2, buffer, idx);
	return (count);
}

/**
 * _printf - Printf
 * @format: String to print
 *
 * Return: Number of chars printed
 */
int _printf(const char *format, ...)
{
	int count = 0, i, space, j, idx = 0;
	char *buffer;
	va_list args;
	t2f types[] = {{'c', print_char}, {'s', print_string},
	{'%', print_percent}, {'d', print_int}, {'i', print_int},
	{'b', print_base}, {'x', print_base}, {'X', print_base},
	{'o', print_base}, {'u', print_int}, {'\0', NULL}};

	buffer = malloc(sizeof(char) * BUFF_SIZE);
	if (!format || !buffer)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			space = 0;
			for (; format[i] == ' '; i++)
				space = 1;
			if (!format[i])
				return (-1);
			for (j = 0; j < 11; j++)
			{
				if (types[j].c == format[i])
				{
					count += types[j].f(args, format[i], buffer, &idx);
					break;
				}
				else if (!types[j].c)
					count += print_none(format[i], space, buffer, &idx);
			}
		}
		else
		{
			buffer_insert(format[i], buffer, &idx);
			count++;
		}
	}
	flush(buffer, &idx);
	va_end(args);
	return (count);
}
