#include "main.h"

/**
 * int_len - Gets length of int
 * @num: Number
 * Return: Length
 */
int int_len(int num)
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

/**
 * print_int - Prints Int
 * @args: args
 * Return: Length of int
 */
int print_int(va_list args)
{
	int i, digit, tens = 1, num, count = 0, len;
	char neg_sign = 45;

	num = va_arg(args, int);
	if (num < 0)
	{
		write (1, &neg_sign, 1);
		count++;
		num *= -1;
	}

	len = int_len(num);
	count += len;

	for (i = 1; i < len; i++)
	{
		tens *= 10;
	}

	while (tens)
	{
		digit = num / tens;
		digit += '0';
		num %= tens;
		write (1, &digit, 1);
		tens /= 10;
	}

	return (count);
}
