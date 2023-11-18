
#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - sums all arguments
 * @separator: first argument
 * @n: second argument
 * Return: nothing.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	va_start(args, format);
	int index = 0;

	while (format[index])
	{
		if (format[index] == 'c')
		{
			print_char(&args);
		}
		else if (format[index] == 'i')
			print_int(&args);
		else if (format[index] == 's')
			print_string(&args);

	
		index++;
	}

	printf("\n");

	va_end(args);
}


void print_int(va_list *args)
{
	int d = va_arg(*args, int);
	printf("%d", d);
}

void print_string(va_list *args)
{
	char *s = va_arg(*args, char *);
	printf("%s", s);
}

void print_char(va_list *args)
{
	int c = va_arg(*args, int);
	printf("%c", c);
}

void print_float(va_list *args)
{
	double f = va_arg(*args, double);
	printf("%f", f);
}
