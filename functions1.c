#include "main.h"

/**
 * base_checker - includes the "A,B,C, ..." after 
 * the digit 9 in uppercase or lowercase as needed
 * @num: the number to convert
 * @p: pointer to variable to store the char
 * @letter_case: To check if capital or small
 *
 * Return: nothing
 */
void base_checker(unsigned int num, char *p, char letter_case)
{
	if (num >= 10)
	{
		if (letter_case >= 97 && letter_case <= 122)
			*p = (num % 10) + 'a';
		else
			*p = (num % 10) + 'A';
	}
	else
		*p = num + '0';
}

/**
 * print_base - Prints a number to any base from decimal
 * @num: Number to be converted
 * @base: Base to be converted to
 * @letter_case - Checks if the letters (numbers after 9)
 * should be capital or small
 * @p: Pointer to keep track of how 
 * many function calls happened
 *
 * Returns: Nothing
 */
void print_base_rec(unsigned int num, unsigned int base, char letter_case, unsigned int *p)
{
	char c = '\0';

	if (num < base)
	{
		base_checker(num, &c, letter_case);
		write(1, &c, 1);
		(*p)++;
		return;
	}
	print_base_rec((unsigned int) (num / base), base, letter_case, p);
	base_checker(num % base, &c, letter_case);
	write(1, &c, 1);
	(*p)++;
}

/**
 * print_base - Prints a number in any base from decimal
 * @args: Number to be converted
 * @base: Base
 *
 * Return: length of base characters
 */
int print_base(va_list args, char base_char)
{
	unsigned int num, len = 0, base;

	num = va_arg(args, unsigned int);

	switch (base_char)
	{
		case 'b':
			base = 2;
			break;
		case 'x':
		case 'X':
			base = 16;
			break;
		case 'o':
			base = 8;
	}

	print_base_rec(num, base, base_char, &len);
	return (len);
}
