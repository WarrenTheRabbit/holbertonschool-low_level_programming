#include "main.h"

/**
 * create_file - function
 * @filename: parameter
 * @text_content: parameter
 * Return: int
 */
int create_file(const char *filename, char *text_content)
{
	ssize_t bytes_written;
	ssize_t fd;
	ssize_t FILE_MAY_EXIST_ALREADY = -1;
	ssize_t FAILED_TO_OPEN_OR_CREATE_FILE = -1;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_EXCL, S_IRUSR | S_IWUSR);

	if (fd == FILE_MAY_EXIST_ALREADY)
	{
		fd = open(filename, O_WRONLY | O_TRUNC);
	}

	if (fd == FAILED_TO_OPEN_OR_CREATE_FILE)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		bytes_written = write(fd, text_content, strlen(text_content));
		if (bytes_written == -1)
		{
			close(fd);
			return (-1);
		}

	}

	close(fd);
	return (1);

}
