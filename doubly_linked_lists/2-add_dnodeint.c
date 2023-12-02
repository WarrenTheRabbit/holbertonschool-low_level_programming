#include "lists.h"

/**
 * add_dnodeint - creates a new node in a linked list
 * @n: string to store in the new node
 * @head: pointer to the current head of the list
 *
 * Description: This function dynamically allocates memory for a new
 * node in a linked list, duplicates the string 'str' and assigns it to
 * the 'str' member of the node. The 'len' member is set to the length of
 * 'str', and 'next' is set to the current head of the list. If memory
 * allocation fails, the function returns NULL.
 *
 * Return: a pointer to the newly created node, or NULL if memory
 * allocation fails
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *first_node = malloc(sizeof(*first_node));

	if (!first_node)
	{
		return (0);
	}

	if (!*head)
	{
		first_node->prev = NULL;
		first_node->next = NULL;
		first_node->n = n;
	}
	else
	{
		first_node->prev = NULL;
		first_node->next = *head;
		first_node->n = n;
		(*head)->prev = first_node;
		
	}
	*head = first_node;
	return (*head);
}
