
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

	if (!current_node && idx == 0)
	{
		new_node->n = n;
		new_node->prev = NULL;
		new_node->next = NULL;
		*h = new_node;

	}

	while (current_index < idx && current_node->next)
	{
		current_index++;
		current_node = current_node->next;
	}

	if (current_index == 0)
	{
		new_node->n = n;
		new_node->next = NULL;
		new_node->prev = NULL;
		*h = new_node;
		return (new_node);
	}

	if (current_index == idx)
	{
		new_node->n = n;
		new_node->next = current_node;
		new_node->prev = current_node->prev;
		current_node->prev->next = new_node;
		current_node->prev = new_node;
		return (new_node);
	}
	else if (current_index + 1 == idx)
	{
		new_node->n = n;
		new_node->prev = current_node;
		new_node->next = NULL;
		current_node->prev->next = new_node;
		current_node->prev = new_node;
		return (new_node);
	}
	else
	{
		free(new_node);
		return (NULL);
	}
}
