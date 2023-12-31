#include "main.h"

/**
 * main - entry point
 *
 *
 */
int main(int argc, char **argv)
{
	char *file_from;
	char *file_to;
	char buffer[1024];
	int to_fd, from_fd;
	ssize_t bytes_read, bytes_written;
	

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = argv[1];
	file_to = argv[2];

	to_fd = open(file_to, O_WRONLY | O_CREAT | O_EXCL | O_TRUNC, 
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

	if (to_fd == -1)
	{
		/*File possibly exists already. */
		to_fd = open (file_to, O_WRONLY | O_TRUNC);
	}


	from_fd = open(file_from, O_RDONLY);

	if (from_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close(to_fd);
		exit(98);
	}

	while ((bytes_read = read(from_fd, buffer, 1024)) > 0)
	{

		bytes_written = write(to_fd, buffer, bytes_read);

		if (bytes_written != bytes_read) 
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close(from_fd);
			close(to_fd);
			exit(99);
		}

	}


	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close(to_fd);
		exit(98);
	}

	if (close(from_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from_fd);
		exit(100);
	}
	
	if (close(to_fd) == -1)
	{                
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from_fd);
                exit(100);		
	}

	return (EXIT_SUCCESS);
		
}
