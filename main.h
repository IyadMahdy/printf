#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>


/**
 * struct types - ...
 * @c: char
 * @f: Pointer to function
 */
typedef struct types
{
	char c;
	int (*f)(va_list);
} t2f;

int int_len(long int num);
int print_int(va_list args);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_none(char c, int space);
int _printf(const char *format, ...);

#endif
