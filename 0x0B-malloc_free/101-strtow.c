#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * count_words - count the number of words in a string
 * @str: the string to count words in
 *
 * Return: the number of words in the string
 */
int count_words(char *str)
{
	int i, in_word = 0, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (isspace(str[i]))
		{
			if (in_word)
			{
				in_word = 0;
				count++;
			}
		}
		else
		{
			in_word = 1;
		}
	}

	if (in_word)
	{
		count++;
	}

	return (count);
}

/**
 * strtow - split a string into words
 * @str: the string to split
 *
 * Return: a pointer to an array of strings (words),
 * or NULL if str is NULL or ""
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, len, num_words;

	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}

	num_words = count_words(str);

	words = malloc(sizeof(char *) * (num_words + 1));
	if (words == NULL)
	{
		return (NULL);
	}

	for (i = 0, j = 0; i < num_words; i++)
	{
		while (isspace(str[j]))
		{
			j++;
		}

		len = 0;
		while (str[j + len] != '\0' && !isspace(str[j + len]))
		{
			len++;
		}

		words[i] = malloc(sizeof(char) * (len + 1));
		if (words[i] == NULL)
		{
			for (k = 0; k < i; k++)
			{
				free(words[k]);
			}
			free(words);
			return (NULL);
		}

		strncpy(words[i], &str[j], len);
		words[i][len] = '\0';

		j += len;
	}

	words[num_words] = NULL;

	return (words);
}

