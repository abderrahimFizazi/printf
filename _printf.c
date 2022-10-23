#include "main.h"

/**
 * get_format - selects print format
 * @s: format selector
 *
 * Return: pointer to a function
*/
int (*get_format(char s))(va_list, flag_t *)
{
	print_t prt[] = {
		{"c", print_char},
		{"s", print_string},
	};

	int flags = 2;

	register int i;

	for (i = 0; i < flags; i++)
	{
		if (prt[i].t == s)
			return (prt[i].f);
	}
	return (NULL);
}

/**
 * _printf - a function that produces output
 * according to a format
 * @format: types of arguments passed to the function
 *
 * Return: number of characters printed
*/
int _printf(const char *format, ...)
{
	int (*pf)(va_list, flag_t *);
	const char *p;
	va_list arguments;
	flag_t flags = {0, 0, 0};

	register int count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pf = get_format(*p);
			count += (pf)
				? pf(arguments, &flags)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arguments);
	return (count);
}
