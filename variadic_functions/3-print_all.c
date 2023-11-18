#include "variadic_functions.h"

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
	int index = 0;
	int j = 0;
	va_start(args, format);

	while (format && format[index])
	{
		j = 0;
		while (handlers[j].type_id && handlers[j].type_id != format[index]) 
		{
			j++;
		}
		handlers[j].handler(&args);
		index++;	
		
		if (format[index] != '\0')
			printf(", ");

	}

	printf("\b\b\b\b\b\n");

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
	if (s == NULL)
	{
		s = "(nil)";
	}
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

