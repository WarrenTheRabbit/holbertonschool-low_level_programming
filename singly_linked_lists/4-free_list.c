#include "lists.h"

/**
 * free_list - frees all memory in the linked list
 * @head: pointer to a linked list node
 * Returns: void
 */
void free_list(list_t *head)
{
	if (!head)
		return;

	if (head->next)
	{
		free_list(head->next);
	}
	free(head->str);
	free(head);
}
