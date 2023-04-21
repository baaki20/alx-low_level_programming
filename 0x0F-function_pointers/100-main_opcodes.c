#include <stdio.h>
#include <stdlib.h>

#define MAX_BYTES 100

/**
 * main - prints the opcodes of its own main function
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on invalid argument count, 2 on negative byte count
 */
int main(int argc, char **argv)
{
	int bytes, i;
	char *main_ptr = (char *) main;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	bytes = atoi(argv[1]);
	if (bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	if (bytes > MAX_BYTES)
		bytes = MAX_BYTES;

	for (i = 0; i < bytes - 1; i++)
		printf("%02x ", (unsigned char) main_ptr[i]);

	printf("%02x\n", (unsigned char) main_ptr[i]);

	return (0);
}

