#include "hash_tables.h"

/**
 * key_index - function
 * @key: key to get index for
 * @size: size of array to index into
 * Return: index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash, index;

	hash = hash_djb2(key);
	index = hash % size;

	return (index);
}
