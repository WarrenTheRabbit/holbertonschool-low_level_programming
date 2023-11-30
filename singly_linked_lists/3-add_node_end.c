#include "lists.h"


/**
 * _strlen - calculates the length of a string
 * @str: constant pointer to the string
 *
 * Description: Iterates over each character in the string
 * pointed to by 'str', increments a counter for each character
 * until it reaches the null terminator, then returns the length.
 *
 * Return: The length of the string.
 */
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

/**
 * new_node - creates a new node in a linked list
 * @str: constant pointer to a string to store in the new node
 * @next: pointer to the next node in the list
 *
 * Description: Dynamically allocates memory for a new node, duplicates
 * the string 'str', and initializes the node's members. If allocation
 * fails at any step, it ensures no memory is leaked before returning NULL.
 *
 * Return: A pointer to the newly created node, or NULL if an error occurs.
 */
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

	return (node);
}

/**
 * add_node_end - adds a new node at the end of a linked list
 * @head: double pointer to the head of the list
 * @str: constant pointer to a string to be added in the new node
 *
 * Description: Adds a new node at the end of a linked list. If the list
 * is empty, the new node is added as the head. The function iterates
 * through the list to find the last node and appends the new node.
 *
 * Return: A pointer to the new node, or NULL if it fails.
 */
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
