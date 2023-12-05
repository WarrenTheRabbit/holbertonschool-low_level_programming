#include "main.h"

/**
 * read_textfile - function
 * @filename: parameter
 * @letters: parameter
 * Return: number of read and printed bytes
 */
ssize_t read_textfile(char const *filename, size_t letters)
{
	char *buffer;
	ssize_t fd;
	ssize_t n;

	if (!filename)
	{
		return (0);
	}

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		return (0);
	}

	buffer = malloc(sizeof(char) * letters);

	if (!buffer)
	{
		return (0);
	}

	n = read(fd, buffer, letters);

	if (n == -1)
	{
		free(buffer);
		return (0);
	}
	
	n = write(1, buffer, letters);

	close(fd);

	return (n);
	
}
