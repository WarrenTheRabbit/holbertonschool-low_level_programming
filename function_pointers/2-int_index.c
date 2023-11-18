
#include "function_pointers.h"

/**
 * int_index - something
 * @array: pointer to int
 * @size: size counter
 * @comp: funciton that returns void and takes one int parameter
 * Return: the index of the first match or -1 if no matches
 */
int int_index(int *array, int size, int (*comp)(int))
{
	int index;
	int comparison_flag;

	if (size <= 0)
	{
		return (-1);
	}

	if (array == NULL || comp == NULL)
		return (-1);

	for (index = 0; index < size; index++)
	{
		comparison_flag = comp(array[index]);
		if (comparison_flag != 0)
		{
			return (index);
		}
	}

	return (-1);
}
