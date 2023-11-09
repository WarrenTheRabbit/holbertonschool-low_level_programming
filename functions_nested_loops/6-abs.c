#include "main.h"

/**
 * _abs - writes the character c to stdout
 * @n: input
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _abs(int n)
{

	if (n < 0)
	{
		return (n * -1);
	}
	return (n);

}
