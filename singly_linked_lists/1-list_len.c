#include "lists.h"

/**
 * list_len - returns length of list
 * @h: pointer to list_t
 * Returns: length of linked list
 */
size_t list_len(const list_t *h)
{
	size_t length = 0;
	list_t *head = (list_t *)h;

	while (head)
	{
		length++;
		head = head->next;
	}

	return (length);
}
