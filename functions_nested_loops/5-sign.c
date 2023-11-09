#include <stdlib.h>
#include "main.h"

int get_type_of_integer(int n);
void print_integer_type(int n);

/**
 * print_sign - prints
 * @n: int
 * Return int
 */
int print_sign(int n)
{
	int integer_type = get_type_of_integer(n);

	print_integer_type(integer_type);
	return (integer_type);

}

/**
 * get_type_of_integer - prints
 * @n: int
 * Return int
 */
int get_type_of_integer(int n)
{
	if (n > 0)
	{
		return (1);
	}	
	else if (n < 0)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}

/**
 * print_integer_type - prints
 * @n: int
 * Return int
 */
void print_integer_type(int integer_type)
{
	if (integer_type == 1)
	{
		_putchar('+');
	}
	else if (integer_type == -1)
	{
		_putchar('-');
	}
	else
	{
		_putchar('0');
	}
}
