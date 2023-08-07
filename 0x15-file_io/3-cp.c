#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
 * open_files - Opens source and destination files.
 * @src: The source file name.
 * @dest: The destination file name.
 *
 * Return: Array of file descriptors.
 */
int *open_files(const char *src, const char *dest)
{
	int *fds = malloc(2 * sizeof(int));

	if (fds == NULL)
		exit(99);

	fds[0] = open(src, O_RDONLY);
	if (fds[0] == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		free(fds);
		exit(98);
	}

	fds[1] = open(dest, O_WRONLY | O_CREAT | O_TRUNC,
				  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fds[1] == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
		close(fds[0]), free(fds);
		exit(99);
	}

	return (fds);
}

/**
 * main - Copies the content of one file to another.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: 0 on success, or error codes as specified.
 */
int main(int argc, char *argv[])
{
	int *fds;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
	fds = open_files(argv[1], argv[2]);

	while ((bytes_read = read(fds[0], buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fds[1], buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fds[0]), close(fds[1]), free(fds);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(fds[0]), close(fds[1]), free(fds);
		exit(98);
	}
	if (close(fds[0]) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fds[0]);
		exit(100);
	}
	if (close(fds[1]) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fds[1]);
		exit(100);
	}
	free(fds);
	return (0);
}

