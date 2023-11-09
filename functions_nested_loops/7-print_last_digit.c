#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * print_last_digit - writes the character c to stdout
 * @n: number
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_last_digit(int n)
{
	int last_digit = _abs(n) % 10;

	_putchar('0' + last_digit);
	return (last_digit);
}

/**
 * _abs - writes the character c to stdout
 * @n: number
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _abs(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}
