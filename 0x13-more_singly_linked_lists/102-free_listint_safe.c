#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: Pointer to pointer to the first node of the linked list.
 *
 * Return: The size of the list that was free'd.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *current, *tmp;

	if (h == NULL)
		return (0);

	current = *h;
	while (current != NULL)
	{
		len++;
		if (current < current->next)
		{
			tmp = current;
			current = current->next;
			free(tmp);
		}
		else
		{
			free(current);
			break;
		}
	}
	*h = NULL;

	return (len);
}

