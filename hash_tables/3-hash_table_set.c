#include "hash_tables.h"



/**
 * prepend_node - function
 * @list: linked list
 * @node: node to prepend
 * Return: 1 on success, 0 on failure.
 */
int prepend_node(hash_node_t **list, hash_node_t *node)
{
	if (list == NULL)
		return (0);

	node->next = *list;
	*list = node;
	return (1);
}

/**
 * initialise_node - function
 * @node: reference to node
 * @key: key
 * @value: value
 * Return: 1 on success, 0 on failure.
 */
int initialise_node(hash_node_t **node, char const *key, char const *value)
{
	hash_node_t *new_node = malloc(sizeof(**node));

	if (!new_node)
	{
		return (0);
	}

	new_node->key = strdup(key);
	new_node->value = strdup(value);

	if (!new_node->key || !new_node->value)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}

	*node = new_node;

	return (1);
}


/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table
 * @key: a key to be indexed to @ht
 * @value: a value to be stored at @key
 * Return: success message.
 */
int hash_table_set(hash_table_t *ht, char const *key, char const *value)
{
	unsigned long int index;
	hash_node_t *node;

	/*
	 * Assert set operation's preconditions: a hash table exists and the key
	 * is a non-empty string.
	 */
	if (!ht || !key || !*key)
		return (0);

	index = key_index((unsigned char const *)key, ht->size);

	/* Handle two cases: key exists already and key doesn't exist already */
	if (ht->array[index] && strcmp(ht->array[index]->key, key) == 0)
	{
		/* Key exists already: update node. */
		free(ht->array[index]->value);
		ht->array[index]->value = strdup(value);
	}
	else
	{
		/* Key does not exist already: insert node. */
		if (!initialise_node(&node, key, value)
		|| !prepend_node(&ht->array[index], node))
			return (0);
	}

	return (1);

}
