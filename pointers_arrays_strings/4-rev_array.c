#include "main.h"
#include "main.h"
#include <stddef.h>
/**
 * reverse_array - description
 * @a: pointer to char
 * @n: pointer to char
 * Return: 0 if equal, negative or positive if not
 */
void reverse_array(int *a, int n)
{
	int i;
	int temp;

	for (i = 0; i < n/2; i++)
	{
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;		
	}
}
