#include "main.h"
#include <stdio.h>
/**
 * print_binary - prints number as binary
 * @n: unsigned number
 * Return: nothing
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = (unsigned long int)1 << (sizeof(n) * 8 - 1);
	int bits = sizeof(n) * 8;
	int index = 0;
	int should_print = 0;

	for (index = 0; index < (bits - 1); index++)
	{
		if (n & mask)
		{
			should_print = 1;
			_putchar('1');
		}
		else if (should_print)
		{
			_putchar('0');
		}
		mask >>= 1;
	}

	if (n & mask)
	{
		_putchar('1');
	}
	else
	{
		_putchar('0');
	}
}

