#include "main.h"
#include <stddef.h>
/**
 * _atoi - convert string to integer
 * @s: pointer to a char
 * Return: extracted integer from string.
 */
int _atoi(char *s)
{
	int sign = 1;
	size_t index = 0;
	int number = 0;
/** search for first digit and determine sign of number */
	while (1)
	{

		if (s[index] == '\0')
		{
			break;
		}

		if (s[index] == '-')
		{
			sign *= -1;
		}

		if (s[index] >= '0' && s[index] <= '9')
		{
			break;
		}

		index++;
	}
/**  accumulate characters into a digit */
	while (1)
	{
		if (s[index] == '\0')
		{
			break;
		}
		/** terminate when non-digit character found. */
		if (s[index] < '0' || s[index] > '9')
		{
			break;
		}
		number *= 10;
		number += (s[index] - '0');

		index++;

	}

	return (sign * number);
}



