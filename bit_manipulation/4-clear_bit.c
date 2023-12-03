
#include "main.h"

/**
 * clear_bit - Gets the value of the bit at a given index.
 * @n: n
 * @index: index
 * Return: 1 if not -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bit_value;

	if (index >= sizeof(n) * 8)
	{
		return (-1);
	}

	bit_value = 1 << index;

	if (*n & bit_value)
	{
		*n = *n - bit_value;
		return (1);
	}
	else
	{
		return (1);
	}
}



