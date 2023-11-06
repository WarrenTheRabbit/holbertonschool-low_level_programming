#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry
 * Return: always 0
 */
int main(void)
{
	int start = '0';
	int end = '9';
	int current = start;

	while (current <= end)
	{
		putchar(current);
		if (current < '9')
		{
			putchar(',');
			putchar(' ');
		}
		current++;
	}
	putchar('\n');
	return (EXIT_SUCCESS);
}

