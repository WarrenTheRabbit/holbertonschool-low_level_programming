#include <stdio.h>
#include "main.h"


/**
 * factorial - calculates factorial
 * @n: number to calculate factorial of
 * Return: Factorial of number
 */
int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0)
	{
		return (1);
	}
	else
	{
		return (n  *  factorial(n - 1));
	}
}
