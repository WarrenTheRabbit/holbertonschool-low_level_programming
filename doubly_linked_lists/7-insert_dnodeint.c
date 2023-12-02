
#include "lists.h"


/**
 * insert_dnodeint_at_index - returns sum of nodes in linked list
 * @h: memory address of linked list
 * @idx: index to insert node at
 * @n: value for inserted node
 * Return: modified linked list
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node = malloc(sizeof(*new_node));
	dlistint_t *current_node = *h;
	unsigned int current_index = 0;

	if (!new_node)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	/* Handle insertions that require no iteration first. 
	 * - inserting a node at the start of an empty list
	 * - inserting a node at the start of a nonempty list
	 */

	/* The start of an empty list */
	if (!h && !idx)
	{
		*h = new_node;
		return (new_node);
	}


	/* The start of a nonempty list */
	if (h && !idx)
	{
		new_node->next = current_node;
		current_node->prev = new_node;
		*h = new_node;
		return (new_node);
	}

	/* Handle the cases that require iteration 
	 * - between two nodes
	 * - at the end of the list
	 * - insertion point not in range
	 */

	while (current_node->next && (current_index + 1) < idx)
	{
		current_index++;
		current_node = current_node->next;
	}


	/* Between two nodes */
	if (current_node->next)
	{
		new_node->next = current_node->next;
		current_node->next->prev = new_node;
		current_node->next = new_node;
		new_node->prev = current_node;
		return (new_node);
	}
	/* At the end of the list */
	else if (current_index + 1 == idx)
	{
		current_node->next = new_node;
		new_node->prev = current_node;
		return (new_node);
	}
	/* Insertion point not in range */
	else
	{
		free(new_node);
		return (NULL);
	}
}

