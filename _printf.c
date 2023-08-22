#include "main.h"

/**
 * print_none - For when the format specifier is unknown
 * @c: char
 * @space: Checks space
 *
 * Return: Number of chars printed
 */
int print_none(char c, int space)
{
	char c2, pcnt, spc;
	int count = 2;

	c2 = c;
	pcnt = 37;
	spc = 32;
	write(1, &pcnt, 1);

	if (space)
	{
		write(1, &spc, 1);
		count++;
	}
	write(1, &c2, 1);
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
	int count = 0, i, space, j;
	va_list args;

	t2f types[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i++] == '%')
		{
			space = 0;
			for (; format[i] == ' '; i++)
				space = 1;
			if (!format[i])
				return (-1);
			for (j = 0; j < 4; j++)
			{
				if (types[j].c == format[i])
				{
					count += types[j].f(args);
					break;
				}
				else if (!types[j].c)
					count += print_none(format[i], space);
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
