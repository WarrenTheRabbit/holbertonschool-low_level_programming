#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point for Task 2 - Variables, if, else...
 * Return: Always 0 (Success)
 */
int main(void)
{
	int a = 97;
	int z = a + 25;

	while (a <= z)
	{
		putchar(a);
		a++;
	}
	putchar('\n');

	return (EXIT_SUCCESS);
}
