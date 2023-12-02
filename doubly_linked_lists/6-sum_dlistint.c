#include "lists.h"


/**
 * sum_dlistint - returns sum of nodes in linked list
 * @head: pointer to linked list
 * Return: sum of all nodes
 */
int sum_dlistint(dlistint_t *head)
{
	long sum = 0;
	dlistint_t *current = head;

	while (current)
	{
		sum += current->n;
		current = current->next;
	}

	if (sum > INT_MAX)
	{
		return (-1);
	}
	else
	{
		return ((int)sum);
	}
}
