
#include <stdio.h>
#include <stdarg.h>


/**
 * print_strings - sums all arguments
 * @separator: first argument
 * @n: second argument
 * Return: nothing.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;


	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		printf("%s", va_arg(args, char *));
		if (i != (n - 1) && separator != NULL)
		{
			printf("%s", separator);
		}
	}

	printf("\n");

	va_end(args);
}
