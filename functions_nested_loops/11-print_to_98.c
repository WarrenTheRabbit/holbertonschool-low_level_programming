#include <stdlib.h>
#include "main.h"

/**
 * print_to_98 - writes the character c to stdout
 * @n: number
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void print_to_98(int n)
{
	int i;
	for (i = n; i < 98, ++i)
	{
		_putchar('0' + i);
		_putchar(',');
		_putchar(' ');
	}
	_putchar('0' + 98);
}
