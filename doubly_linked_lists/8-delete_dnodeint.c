#include "lists.h"


/**
 * delete_dnodeint_at_index - returns sum of nodes in linked list
 * @head: memory address of linked list
 * @index: index to insert node at
 * Return: modified linked list
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current_node = *head;
	unsigned int current_index = 0;

	/* Handle cases that requires no iteration first.*/
	/* - cannot delete a node from an empty list. */
	/* - deleting first node of a size 1 list. */


	/* Deleting from an empty list */
	if (!current_node)
	{
		return (-1);
	}


	/* The only element in the list */
	if (index == 0 && current_node && !current_node->next)
	{
		*head = NULL;
		free(current_node);
		return (1);
	}

	/* The first element in a list with 2 or more elemnets */
	if (index == 0 && current_node && current_node->next)
	{
		*head = current_node->next;
		current_node->next->prev = NULL;
		free(current_node);
		return (1);
	}

	/* Handle the cases that require iteration
	 * - between two nodes
	 * - at the end of the list
	 * - insertion point not in range
	 */

	while (current_node && (current_index < index))
	{
		current_index++;
		current_node = current_node->next;
	}


	/* Between two nodes */
	if (current_node && current_node->next && (current_index == index))
	{
		current_node->prev->next = current_node->next;
		current_node->next->prev = current_node->prev;
		free(current_node);
		return (1);
	}
	/* At the end of the list */
	else if (current_index == index && !current_node->next)
	{
		current_node->prev->next = NULL;
		free(current_node);
		return (1);
	}
	/* Insertion point not in range */
	else
	{
		return (-1);
	}
}

