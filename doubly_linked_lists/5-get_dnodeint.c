#include "lists.h"

/**
 * get_dnodeint_at_index - gets node at specific index
 * @head: pointer to head of doubly linked list
 * @index: index of node to retrieve
 * Return: node in doubly linked list at provided index
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int current = 0;

	if (!head)
	{
		return (0);
	}

	while (head->next && current < index)
	{
		head = head->next;
		current++;
	}


	if (current == index)
	{
		return (head);
	}
	else
	{
		return (NULL);
	}
}
