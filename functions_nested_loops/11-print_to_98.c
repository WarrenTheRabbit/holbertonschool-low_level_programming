#include <stdlib.h>
#include "main.h"

void print_digits(int number);
void print_98(void);
void print_ascending_numbers(int n);
void print_descending_numbers(int n);
void print_number(int number);

/**
 * print_to_98 - writes the character c to stdout
 * @n: number
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void print_to_98(int n)
{
	if (n < 98)
	{
		print_ascending_numbers(n);
	}
	else if (n > 98)
	{
		print_descending_numbers(n);
	}

	print_98();
	
}

void print_98(void)
{
	print_digits(98);
	_putchar('\n');
}


void print_ascending_numbers(int n)
{
	int i;
	for (i = n; i < 98; ++i)
	{
		print_number(i);
	}
}

void print_descending_numbers(int n)
{
	int i;
	for (i = n; i > 98; --i)
	{
		print_number(i);
	}
}

void print_number(int number)
{
	int absolute = number; 

	if (number < 0)
	{
		absolute = number * -1;
		_putchar('-');
	}

	print_digits(absolute);
	_putchar(',');
	_putchar(' ');
}

void print_digits(int number)
{
	int terminal_digit = number % 10;

	if (number >= 10)
	{
		print_digits(number / 10);
	}
	_putchar('0' + terminal_digit);
}
