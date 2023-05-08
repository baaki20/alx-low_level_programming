#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * read_file - it reads the contents of a file into a string
 *
 * @filename: name of the file to read
 * @max_chars: maximum number of characters to read
 *
 * Return: a string containing the file contents, or NULL on failure
 */
char *read_file(const char *filename, size_t max_chars)
{
	int fd;
	char *buf;
	ssize_t num_read;

	if (filename == NULL)
		return (NULL);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);

	buf = malloc(max_chars + 1);
	if (buf == NULL)
	{
		close(fd);
		return (NULL);
	}

	num_read = read(fd, buf, max_chars);
	if (num_read == -1)
	{
		free(buf);
		close(fd);
		return (NULL);
	}

	buf[num_read] = '\0';

	close(fd);

	return (buf);
}

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 *
 * @filename: name of the file to read
 * @max_chars: maximum number of characters to read and print
 *
 * Return: the actual number of characters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t max_chars)
{
	char *buf;
	ssize_t num_written;

	buf = read_file(filename, max_chars);
	if (buf == NULL)
		return (0);

	num_written = write(STDOUT_FILENO, buf, strlen(buf));
	if (num_written == -1)
	{
		free(buf);
		return (0);
	}

	free(buf);

	return (num_written);
}

