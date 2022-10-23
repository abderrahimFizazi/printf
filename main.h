#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct prt - struct op
 * @t: the operator
 *
 * @f: associated function
*/
typedef struct prt
{
	char t;
	int (*f)(va_list);
} print_t;

/**
 * struct flags - struct for flags to use
 * @plus: flag for '+'
 * @space: flag for ' '
 * @hash: flag for '#'
*/
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flag_t;

/* printf */
int _printf(const char *format, ...);
int get_flag(char s, flag_t *f);
int (*get_format(char s))(va_list, flag_t *);

/* print char*/
int print_char(va_list c, flag_t *f);
int print_string(va_list s, flag_t *f);

/* Write Function */
int _putchar(char c);
int _puts(char *str);

#endif
