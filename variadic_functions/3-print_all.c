
#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
void print_char(va_list *);

typedef void (*print_handler)(va_list *);

typedef struct {
    char type_id;
    print_handler handler;
} TypeHandler;

TypeHandler handlers[] = {
    {'c', print_char},
    {'s', print_string},
    {'i', print_int},
    {'f', print_float},
    {0, NULL}  
};


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
	int j = 0;

	while (format[index])
	{
		j = 0;
		while (handlers[j].type_id)
		{
			if (handlers[j].type_id == format[index])
			{
				handlers[j].handler(&args);

				if (format[index + 1] != '\0')
					printf(", ");
			}
			j++;
		}
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
	char c = va_arg(*args, int);
	printf("%c", c);
}

void print_float(va_list *args)
{
	double f = va_arg(*args, double);
	printf("%f", f);
}
