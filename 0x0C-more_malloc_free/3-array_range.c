#include <stdlib.h>

/**
 * array_range - Creates an array of integers from min to max
 * @min: The minimum value of the array
 * @max: The maximum value of the array
 *
 * Return: A pointer to the newly created array
 *         NULL on failure or if min > max
 */
int *array_range(int min, int max)
{
	int *array, i;

	if (min > max)
		return (NULL);

	array = malloc(sizeof(int) * (max - min + 1));
	if (array == NULL)
		return (NULL);

	for (i = 0; i < (max - min + 1); i++)
		array[i] = min + i;

	return (array);
}

