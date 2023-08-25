#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define BUFF_SIZE 1024

/**
 * struct types - ...
 * @c: char
 * @f: Pointer to function
 */
typedef struct types
{
	char c;
	int (*f)(va_list, char, char *, int *);
} t2f;

int int_len(long int num);
int print_int(va_list args, char character, char buffer[], int *idx);
int print_char(va_list args, char character, char buffer[], int *idx);
int print_string(va_list args, char character, char buffer[], int *idx);
int print_percent(va_list args, char character, char buffer[], int *idx);
int print_none(char c, int space, char buffer[], int *idx);
int print_base(va_list args, char character, char buffer[], int *idx);
void print_base_rec(unsigned int num, unsigned int base, char letter_case,
 unsigned int *p, char buffer[], int *idx);
void base_checker(unsigned int num, char *p, char letter_case);
int _printf(const char *format, ...);
void flush(char buffer[], int *idx);
void buffer_insert(char c, char buffer[], int *idx);

#endif
