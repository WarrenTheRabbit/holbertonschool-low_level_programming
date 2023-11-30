#include "lists.h"

/**
 * print_dlistint - prints elements of doubly linked list
 * @h: pointer to a doubly linked list node
 * Return: the number of nodes in the doubly linked list
 */
size_t print_dlistint(dlistint_t const *h)
{
	size_t count = 0;

	if (h == NULL)
	{
		return (0);
	}

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}

	return (count);
}
