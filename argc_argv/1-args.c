#include <stdio.h>
#include <stdlib.h>


/**
 * main - entry point of program
 * @argc - number of arguments passed to program
 * @argv - array of character pointers for arguments
 * Return: Always EXIT_SUCESS.
 */
int main(int argc, char **argv)
{
	(void)argv;
	printf("%d\n", argc - 1);
	return (EXIT_SUCCESS);
}
