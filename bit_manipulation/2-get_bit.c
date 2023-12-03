#include "main.h"
#include <limits.h>

/**
 * is_nth_bit_set - description
 * @number: number
 * @n: index
 * Return: 0 if not set else 1 or greater
 */
unsigned long int is_nth_bit_set(unsigned long int number, unsigned int n)
{
	return (number & 1 << n);
}

/**
 * int get_bit - Gets the value of the bit at a given index.
 * @n: number
 * @index: index
 * Return: 0 if not set else 1
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
	{
		return (-1);
	}

	if (is_nth_bit_set(n, index))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}



