#include "main.h"

/**
 * append_text_to_file - function
 * @filename: parameter
 * @text_content: parameter
 * Return: int
 */
int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t fd, bytes_written;

	fd = open(filename, O_WRONLY | O_APPEND);

	/* File does not exist or there is a permission issue. */
	if (fd == -1)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		return (1);
	}

	bytes_written = write(fd, text_content, strlen(text_content));

	close(fd);
	
	if (bytes_written == -1)
	{
		close(fd);
		return (-1);
	}
	else
	{
		return (1);
	}

}
