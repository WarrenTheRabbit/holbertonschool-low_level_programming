#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

int get_length(char *str);

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
	int length = get_length(s);
	
	if (length > 1) 
	{	
		printf("%s", "Error");
		exit(100);
	}
	

	while (ops[i].op != NULL)
	{
		if (*ops[i].op == *s)
			return (ops[i].f);
		i++;
	}

	return (NULL);

}



int get_length(char *str) 
{
	int length = 0;
	
	while (*str != '\0')
	{
		str++;
		length++;
	}

	return (length);
}
