#include "main.h"

/**
 * print_char - prints a character
 * @c: character to print
 * @f: pointer to struct flags
 * Return: number of characters printed(Always 1)
*/
int print_char(va_list c, flag_t *f)
{
	(void)f;
	_putchar(va_arg(c, int));
	return (1);
}

/**
 * print_string - prints a string
 * @s: string to print
 * @f: pointer to struct flags
 * Return: number of characters printed
*/
int print_string(va_list s, flag_t *f)
{
	char *str = va_arg(s, char *);

	(void)f;

	if (!str)
		str = "(null)";
	return (_puts(str));
}
