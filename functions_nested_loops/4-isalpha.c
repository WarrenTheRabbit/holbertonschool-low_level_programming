#include <stdlib.h>
#include "main.h"

/**
 * _isalpha - writes the character c to stdout
 * @c: character to test for lower case
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _isalpha(int c)
{

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
