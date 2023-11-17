#include "function_pointers.h"




/**
 * array_iterator - something
 * @array: pointer to int
 * @size: size counter
 * @action: funciton that returns void and takes one int parameter
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t index;

	if (array == NULL)
		return;

	for (index = 0; index < size; index++)
	{
		action(array[index]);
	}
}
