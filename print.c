#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: string to print
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list list;
	int (*f)(va_list);
	count = 0;
	unsigned int a = 0;

	if (format ==NULL)
		return (-1);

	va_start(list, format);

	while (format[a])
	{
		for (i = 0; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		if (!format[a])
			return (count);

		f = check_format(&format[a + 1]);
		if (f != NULL)
		{
			count += f(list);
			a += 2;
			continue;
		}
		if (format[a + 1] == '%')
			a += 2;
		else
			a++;
	}
	va_end(list);

	return (count);
}

/**
 * check_format - checks through the format string for printf
 * @format: possible format specifier
 *
 * Return: pointer to function
 */

static int (*check_format(const char *format))(va_list)
{
	unsigned int i;
	print_t set[] ={{"c", print_c},
		{"s", print_s},
		{NULL, NULL}};

	for (i =0; set[i].t != 	NULL; i++)
	{
		if (*set[i].t == *format)
		{
			break;
		}
	}
	return (set[i].f);
}
