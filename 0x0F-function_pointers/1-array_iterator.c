/**
 * array_iterator - Executes a function on each element of an array
 * @array: Array of integers
 * @size: Size of the array
 * @action: Pointer to function that takes an integer and returns nothing
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}

