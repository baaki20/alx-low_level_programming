#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: The name of the file to append to.
 * @text_content: The text content to append.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t bytesWritten;
	int fd;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		ssize_t len = 0;

		while (text_content[len])
			len++;

		bytesWritten = write(fd, text_content, len);

		if (bytesWritten != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
