#include "list.h"
#include <stdio.h>

/**
 * print_list - print the elements in a linked list
 * @h: pointer to a constant list_t
 * Return: size_t (the number of nodes)
 */
size_t print_list(const list_t *h)
{
	char *str;
	int count = 0;
	list_t *head = (list_t *)h;

	while (head)
	{
		_putchar('[');
		_putchar('0' + head->len);
		_putchar(']');
		_putchar(' ');

		if (head->str)
		{
			str = head->str;
			while (*str)
			{
				_putchar(*str++);
			}
		}
		else 
		{
			_putchar('(');
			_putchar('n');
			_putchar('i');
			_putchar('l');
			_putchar(')');
		}
		_putchar('\n');
		count++;
		head = head->next;
	}

	_putchar('\n');
	return (count);
}
