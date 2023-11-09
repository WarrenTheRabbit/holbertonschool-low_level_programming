#include <stdlib.h>
#include <stdio.h>
#include "main.h"

void print_row(int row);
void print_digits(int number);
void print_spaces(int number);
void print_delimiter(void);

/**
 * times_table - writes the character c to stdout
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void times_table(void)
{
	int row;

	for (row = 0; row < 10; ++row)
	{
		print_row(row);
	}	

}

void print_row(int row)
{
	int column, product;

	_putchar('0');

	for (column = 1; column < 10; ++column)
	{
		product = row * column;

		print_delimiter();
		print_spaces(product);
		print_digits(product);	
	}

	_putchar('\n');
	
}

void print_delimiter()
{
	_putchar(',');
}

void print_digits(int number)
{
	int terminal_digit;

	if (number >= 10)
	{
		print_digits(number / 10);
	}
	
	terminal_digit = number % 10;
	_putchar('0' + terminal_digit);	
}

void print_spaces(int number)
{

	if (number < 10)
	{
		_putchar(' ');
	}
	_putchar(' ');
}
