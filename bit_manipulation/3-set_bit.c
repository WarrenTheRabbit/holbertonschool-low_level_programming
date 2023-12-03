#include "main.h"

/**
 * set_bit - Gets the value of the bit at a given index.
 * @n: n
 * @index: index
 * Return: 1 if not -1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
	{
		return (-1);
	}

	*n = *n + (1 << index);
	return (1);
}



