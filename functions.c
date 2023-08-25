#include "main.h"

/**
 * int_len - Gets length of int
 * @num: Number
 * Return: Length
 */
int int_len(long int num)
{
	int count = 0;

	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}

/**
 * print_char - Prints char
 * @args: Pointer to char in parameter
 * @character: character from format
 *
 * Return: Length of char (1)
 */
int print_char(va_list args, char character)
{
	char c = va_arg(args, int);

	(void) character;
	write(1, &c, 1);

	return (1);
}

/**
 * print_string - Prints string
 * @args: String from parameter
 * @character: character from format
 *
 * Return: Length of string
 */
int print_string(va_list args, char character)
{
	int i;
	char *str;

	(void) character;
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
 * @character: character from format
 *
 * Return: 1
 */
int print_percent(va_list args, char character)
{
	char c = 37;

	(void) args;
	(void) character;
	write(1, &c, 1);
	return (1);
}

/**
 * print_int - Prints Int
 * @args: args
 * @character: Character from format
 *
 * Return: Length of int
 */
int print_int(va_list args, char character)
{
	long int num_i, len = 1, count = 0;
	unsigned int num_u, num2, rem, digit;
	char neg = '-';

	if (character == 'u')
		num_u = va_arg(args, unsigned int);
	else
	{
		num_i = va_arg(args, int);
		if (num_i < 0)
		{
			write(1, &neg, 1);
			count++;
			num_i = -num_i;
		}
		num_u = num_i;
	}
	num2 = num_u;
	rem = num_u;
	while (num2 >= 10)
	{
		num2 /= 10;
		len *= 10;
	}
	while (len)
	{
		digit = rem / len;
		rem = rem % len;
		digit = digit + '0';
		write(1, &digit, 1);
		count++;
		len /= 10;
	}
	return (count);
}
