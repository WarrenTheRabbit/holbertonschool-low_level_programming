#include <stdlib.h>
#include <stdio.h>


/**
 * main - entry point
 * @argc: count of arguments from the host environment
 * @argv: array of pointers to strings passed into command line
 * Return: Always EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	/**
	 * The command line passes the name of the program
	 * as the first argument. The index is set to 1 to
	 * skip this unwanted program name argument.
	 */
	int index = 0;

	while (index < argc)
	{
		printf("%s\n", argv[index++]);

	}
	return (EXIT_SUCCESS);
}
