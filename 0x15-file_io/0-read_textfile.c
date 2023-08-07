#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * read_textfile - Reads and prints a text file to the standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed,
 *         0 on error or if filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, bytesRead, bytesWritten;
	char buffer[BUFFER_SIZE];

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	bytesRead = read(fd, buffer, letters);
	if (bytesRead == -1)
	{
		close(fd);
		return (0);
	}

	bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);

	close(fd);

	if (bytesWritten == -1 || bytesWritten != bytesRead)
		return (0);

	return (bytesWritten);
}
