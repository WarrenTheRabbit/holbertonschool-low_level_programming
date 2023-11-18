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
	int index = 0;
	int j = 0;
TypeHandler handlers[] = {
	{'c', print_char},
	{'s', print_string},
	{'i', print_int},
	{'f', print_float},
	{0, print_nothing}
};

	va_start(args, format);

	while (format && format[index])
	{
		j = 0;
		while (handlers[j].type_id != 0 && handlers[j].type_id != format[index])
		{
			j++;
		}
		handlers[j].handler(&args);
		index++;

		if (format[index] != '\0' && handlers[j].handler != print_nothing)
			printf(", ");

	}

	printf("\n");

	va_end(args);
}

void print_nothing(va_list *args)
{
	(void)args;
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

