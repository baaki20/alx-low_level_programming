#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int
 * @b: Pointer to a string of binary characters ('0' and '1')
 *
 * Return: Converted number, or 0 if there are invalid characters or b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int results = 0;

	if (b == NULL)
		return (0);

	while (b[i] != '\0')
	{
		if (b[i] != 0 && b[i] != '1')
			return (0);
		results = results * 2 + (b[i] - '0');
		i++;
	}

	return (results);
}

