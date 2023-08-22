#include "main.h"

/**
 * print_char - Prints char
 * @args: Pointer to char in parameter
 *
 * Return: Length of char (1)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);

	return (1);
}

/**
 * print_string - Prints string
 * @args: String from parameter
 *
 * Return: Length of string
 */
int print_string(va_list args)
{
	int i;
	char *str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";

	for (i = 0; str[i]; i++)
		write(1, &(str[i]), 1);
	return (i);
}

/**
 * print_percent - Prints Percent
 * @args: args
 * Return: 1
 */
int print_percent(va_list args)
{
	char c = 37;

	(void) args;
	write(1, &c, 1);
	return (1);
}
