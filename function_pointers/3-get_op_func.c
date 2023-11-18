#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * get_op_func - entry point
 * @s: pointer to char
 * Return: pointer to function(int, int)
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	if (s == NULL || s[1] != '\0')
	{
		printf("%s\n", "Error");
		exit(99);
	}


	while (ops[i].op != NULL && *ops[i].op != *s)
	{
		i++;
	}

	return (ops[i].f);

}
