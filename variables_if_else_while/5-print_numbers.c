#include <stdio.h>
#include <stdlib.h>
#include "main.h"


void print_digits(void);

/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	print_digits();
	putchar('\n');

	return (EXIT_SUCCESS);
}


/**
 * print_digits - entry point
 * Return: 0
 */
void print_digits(void)
{
	int start_digit = '0';
	int end_digit = '9';
	int current_digit = start_digit;

	while (current_digit <= end_digit)
	{
		putchar(current_digit);
		current_digit++;
	}
}
