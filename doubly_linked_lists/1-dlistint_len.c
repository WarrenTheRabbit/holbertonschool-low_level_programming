#include "lists.h"

/**
 * dlistint_len - returns the length of a doubly-linked int list
 * @h: pointer to node of linked list
 * Return: length of linked list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	if (!h)
	{
		return (0);
	}

	while (h)
	{
		count++;
		h = h->next;
	}

	return (count);
}
