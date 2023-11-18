#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"


/**
 * main - entry point
 * @argc: count of arguments passed in
 * @argv: pointer to argument array
 * Return: 98 incorrect usage, 99 null, 0 success.
 */
int main(int argc, char **argv)
{
	int operand1, operand2, result;
	int (*operator)(int, int);

	if (argc < 4)
	{
		printf("%s\n", "Error");
		return (98);
	}

	operand1 = atoi(argv[1]);
	operand2 = atoi(argv[3]);

	operator = get_op_func(argv[2]);
	if (operator == NULL) {
    		printf("Error\n");
		return (99);
	}

	result = operator(operand1, operand2);
	printf("%d\n", result);

	return (0);
}
