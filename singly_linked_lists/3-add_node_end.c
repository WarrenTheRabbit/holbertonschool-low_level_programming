#include "lists.h"


size_t _strlen(char const *str)
{
	size_t length = 0;
	char const *iterator = str;

	while (*iterator)
	{
		iterator++;
		length++;
	}

	return (length);
}


list_t *new_node(char const *str, list_t *next)
{
	list_t *node = NULL;
	char *allocated_str = NULL;
	size_t length = 0;

	node = malloc(sizeof(*node));

	if (!node)
	{
		return (0);
	}

	allocated_str = strdup(str);

	if (!allocated_str)
	{
		free(node);
		return (0);
	}

	length = _strlen(allocated_str);

	node->str = allocated_str;
	node->len = length;
	node->next = next;
	
}


list_t *add_node_end(list_t **head, char const *str)
{
	list_t *node = NULL;
	list_t *last_node = NULL;

	last_node = *head;

	if (!last_node)
	{
		node = new_node(str, NULL);
		*head = node;
		return (node);
	}

	while (last_node)
	{
		if (last_node->next)
		{
			last_node = last_node->next;
		}
		else
		{
			break;
		}

	}

	node = new_node(str, NULL);
	last_node->next = node;

	return (node);
}

