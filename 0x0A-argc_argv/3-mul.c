#include <stdio.h>

#include "main.h"

/**
 * _atoi-converts a string to an integer
 *@s: string to be converted
 *
 * Return: the int converted from the string
 */

int _atoi(int argc, char* argv[])
{
	if (argc > 2)
	{
		int x = atoi(argv[1]);
		int y = atoi(argv[2]);
		int product = x * y;

		printf("%d\n', product);
	}
	printf("Error");

	return (0);
}
