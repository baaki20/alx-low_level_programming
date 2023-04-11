#include <stdlib.h>
#include <string.h>

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(char *str)
{
	char *dup_str;

	if (str == NULL)
		return (NULL);

	dup_str = malloc(sizeof(char) * (strlen(str) + 1));
	if (dup_str == NULL)
		return (NULL);

	strcpy(dup_str, str);

	return (dup_str);
}

