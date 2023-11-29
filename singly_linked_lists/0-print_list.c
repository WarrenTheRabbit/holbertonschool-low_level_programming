#include "lists.h"
#include <stdio.h>

int _print_digits(unsigned int number)
{
	unsigned int terminal_digit = number % 10;

	if (number > 9)
	{
		_print_digits(number / 10);
	}

	_putchar(terminal_digit);
}


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
		_putchar(head->len + '0');
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

	return (count);
}
