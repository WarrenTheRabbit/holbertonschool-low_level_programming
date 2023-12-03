
#include "main.h"

/**
 * count_set_bits - counts number of bits
 * @n: number to count the bits of
 * Return: number of set bits
 */
unsigned int count_set_bits(unsigned long int n)
{
	unsigned int count = 0;

	while (n)
	{
		count += n & 1;
		n >>= 1;
	}

	return (count);
}

/**
 * flip_bits - Description.
 * @n: n
 * @m: m
 * Return: number of bits you would need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;

	return (count_set_bits(xor_result));
}



