#include "main.h"


/**
 * _binlen - get length of string
 * @b: string
 * Return: size
 */
size_t _binlen(char *b)
{
	size_t length = 0;

	while (*b)
	{
		length++;
		b++;
	}
	return (length);
}


/**
 * _calculate_msb - get the value of the most significant bit
 * @length: length of binary number
 * Return: value of most significant bit
 */
int _calculate_msb(int length)
{
	long value = 1;

	for (; (length - 1) > 0; length--)
	{
		value *= 2;
	}

	return (value);
}


char const *_remove_leading_zeros(char const *b)
{
	while (*b && *b != '1')
	{
		b++;
	}
	
	return (b);
}

/**
 * binary_to_uint - convert binary to unsigned int
 * @b: pointer to binary representation
 * Return: unsigned int
 */
unsigned int binary_to_uint(char const *b)
{
	unsigned int sum = 0;
	size_t length;
	long bit_value;

	b = _remove_leading_zeros(b);
	length = _binlen((char *)b);
	bit_value = _calculate_msb(length);


	if (b == NULL)
	{
		return (0);
	}

	while (*b)
	{
		if (!(*b == '1' || *b == '0'))
		{
			return (0);
		}
		else if (*b == '1')
		{
			sum += bit_value;
		}

		bit_value /= 2;
		b++;
	}

	return (sum);

}
