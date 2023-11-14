#include "main.h"
#include <stdio.h>
/**
 * print_rev - prints string in reverse
 * @str: string to reverse 
 * Return: void.
 */
void print_rev(char *s)
{
	print_rev_recursively(s);
	_putchar('\n');
}

void print_rev_recursively(char *s)
{
	
	char *copy = s;
	
	if (*s == '\0')
	{
		return;
	}
	print_rev_recursively(++copy);	

	_putchar(*s);	
}
