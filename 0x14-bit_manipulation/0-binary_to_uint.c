#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a string of 0 and 1 chars representing the binary number.
 *
 * Return: Converted number, or 0 if there is an invalid char or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int i;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] == '0' || b[i] == '1')
		{
			num <<= 1;
			num += b[i] - '0';
		}
		else
		{
			return (0);
		}
	}

	return (num);
}

