#include "main.h"
#include <stdio.h>
/**
 * print_array - prints n elements
 * @a: something
 * @n: something
 */
void print_array(int *a, int n)
{

	int index = 0;

	if (n <= 0)
	{
		printf("\n");
		return;
	}


	while (index < n - 1)
	{
		printf("%d, ", a[index]);
		index++;
	}

	printf("%d\n", a[index]);

}


