
#include <stdio.h>
#include <stdarg.h>


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
	int print_flag;
	va_start(args, format);

	while (format[index])
	{

		print_flag = 1;

		if (format[index] == 'c')
			printf("%c", va_arg(args, int));
		else if (format[index] == 'i')
			printf("%d", va_arg(args, int));
		else if (format[index] == 'f')
			printf("%f", va_arg(args, double));
		else if (format[index] == 's')
			printf("%s", va_arg(args, char *));
		else
			print_flag = 0;

		if (print_flag && format[index + 1] != '\0')
			printf(", ");

		index++;

	}

	printf("\n");

	va_end(args);
}
