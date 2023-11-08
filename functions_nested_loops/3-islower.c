#include <stdlib.h>
#include "main.h"

/**
 * _islower - writes the character c to stdout
 * @c: character to test for lower case
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _islower(int c)
{
	int start_range = 'a';
	int end_range = 'z';

	if (start_range <= c && end_range >= c)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
