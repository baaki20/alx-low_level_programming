#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int open_file_from(char *file);
int open_file_to(char *file);
int close_files(int fd_from, int fd_to);

/**
 * main - copies the content of a file to another file
 * @ac: the number of arguments
 * @av: the arguments vector
 *
 * Return: 0 on success, otherwise an error code
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, read_bytes, write_bytes;
	char buffer[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_file_from(av[1]);
	if (fd_from == -1)
		exit(98);

	fd_to = open_file_to(av[2]);
	if (fd_to == -1)
		exit(99);

	while ((read_bytes = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		write_bytes = write(fd_to, buffer, read_bytes);
		if (write_bytes == -1 || write_bytes != read_bytes)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			exit(99);
		}
	}

	if (read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	if (close_files(fd_from, fd_to) == -1)
		exit(100);

	return (0);
}

/**
 * open_file_from - opens the file from which content will be copied
 * @file: the file to open
 *
 * Return: the file descriptor on success, -1 on failure
 */
int open_file_from(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);

	return (fd);
}

/**
 * open_file_to - opens the file to which content will be copied
 * @file: the file to open
 *
 * Return: the file descriptor on success, -1 on failure
 */
int open_file_to(char *file)
{
	int fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);

	return (fd);
}

/**
 * close_files - closes the file descriptors
 * @fd_from: the file descriptor for the source file
 * @fd_to: the file descriptor for the destination file
 *
 * Return: 0 on success, -1 on failure
 */
int close_files(int fd_from, int fd_to)
{
	int close_from, close_to;

	close_from = close(fd_from);
	close_to = close(fd_to);

	if (close_from == -1 || close_to == -1)
	{
		if (close_from == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);

		if (close_to == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);

		return (-1);
	}

	return (0);
}

