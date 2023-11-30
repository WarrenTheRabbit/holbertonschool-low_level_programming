#include "lists.h"


/**
 * _strlen - Calculates the length of a string.
 * @str: Pointer to the string to be measured.
 *
 * Description: Iterates through each character of the string
 * pointed to by 'str', incrementing a counter until the end of
 * the string is reached (null character).
 *
 * Return: The length of the string.
 */
int _strlen(char const *str)
{
	size_t length = 0;

	while (*str)
	{
		length++;
		str++;
	}

	return (length);
}


/**
 * new_node - creates a new node in a linked list
 * @str: string to store in the new node
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
list_t *new_node(char *str, list_t *head)
{
	char *allocated_str = strdup(str);
	list_t *node = malloc(sizeof(*node));

	if (!node)
	{
		free(node);
		return (0);
	}

	if (!allocated_str)
	{
		free(allocated_str);
		return (0);
	}


	node->str = allocated_str;
	node->len = _strlen(node->str);
	node->next = head;

	return (node);
}


/**
 * add_node - adds a new node at the beginning of a linked list
 * @head: double pointer to the head of the list
 * @str: string to be included in the new node
 *
 * Description: This function creates a new node with a string 'str'
 * and inserts it at the beginning of a linked list. The new node
 * becomes the new head of the list. If the creation of the new node
 * is successful, the head of the list is updated to point to this new node.
 *
 * The function uses 'new_node' to create the new node and sets the 'next'
 * element of the new node to the current head of the list, effectively
 * inserting it at the beginning. If the new node creation fails, the
 * function returns NULL without altering the list.
 *
 * Return: a pointer to the new head of the list, or NULL if the new node
 * could not be added
 */
list_t *add_node(list_t **head, char *str)
{
	list_t *new_node_ptr = new_node(str, *head);

	if (new_node_ptr)
	{
		*head = new_node_ptr;
	}

	return (new_node_ptr);
}
