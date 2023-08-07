#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_error - Prints an error message and exits with status code 98.
 * @message: The error message to display.
 */
void print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}

/**
 * print_elf_header_info - Displays info contained in the ELF header of a file.
 * @filename: The name of the ELF file to analyze.
 */
void print_elf_header_info(const char *filename)
{
	int i;
	Elf64_Ehdr header;

	int fd = open(filename, O_RDONLY);

	if (fd == -1)
		print_error("Can't open file");

	if (read(fd, &header, sizeof(header)) != sizeof(header))
		print_error("Can't read ELF header");

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
		header.e_ident[EI_MAG1] != ELFMAG1 ||
		header.e_ident[EI_MAG2] != ELFMAG2 ||
		header.e_ident[EI_MAG3] != ELFMAG3)
	{
		print_error("Not an ELF file");
	}

	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; ++i)
	{
		printf("%02x", header.e_ident[i]);
		if (i < EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");

	printf("Class: %s\n", header.e_ident[EI_CLASS] == ELFCLASS64 ?
			"ELF64" : "ELF32");

	printf("Data: %s\n",
			header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
			"2's complement, little endian");
	printf("Version: %d\n", header.e_ident[EI_VERSION]);
	printf("OS/ABI: %d\n", header.e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
	printf("Type: %d\n", header.e_type);
	printf("Entry point address: %lx\n", (unsigned long)header.e_entry);
	close(fd);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	print_elf_header_info(argv[1]);

	return (0);
}

