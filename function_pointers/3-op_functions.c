#include <stdio.h>
#include <stdlib.h>


/**
 * op_add - add operation
 * @a: number 
 * @b: number
 * Return int
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - sub operation
 * @a: number
 * @b: number
 * Return int
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - mul operation
 * @a: number
 * @b: number
 * Return int
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - div operation
 * @a: number
 * @b: number
 * Return int
 */
int op_div(int a, int b)
{
	
	if (b == 0)
	{
		printf("%s\n", "Error");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - mod operation
 * @a: number
 * @b: number
 * Return int
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("%s\n", "Error");
		exit(100);
	}
	return (a % b);
}
