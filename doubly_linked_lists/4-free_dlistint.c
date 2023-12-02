#include "lists.h"

/**
 * free_dlistint - add node to end of d list
 * @head: head of doubly linked list
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *next = NULL;

	if (!head)
	{
		return;
	}

	while (head->next)
	{
		next = head->next;
		free(head);
		head = next;
	}

	free(head);
}
