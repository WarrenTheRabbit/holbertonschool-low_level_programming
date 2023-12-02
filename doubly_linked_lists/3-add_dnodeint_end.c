#include "lists.h"

/**
 * add_dnodeint_end - add node to end of d list
 * @head: head of doubly linked list
 * @n: value of node to insert at end
 * Return: head of doubly-linked list
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *penultimate_node = NULL;
	dlistint_t *end_node = malloc(sizeof(*end_node));

	if (!end_node)
	{
		return (0);
	}

	end_node->n = n;
	end_node->next = NULL;
	end_node->prev = NULL;

	if (!*head)
	{
		*head = end_node;
	}
	else
	{
		penultimate_node = *head;
		while (penultimate_node->next)
		{
			penultimate_node = penultimate_node->next;
		}

		penultimate_node->next = end_node;
		end_node->prev = penultimate_node;

	}


	return (*head);
}
