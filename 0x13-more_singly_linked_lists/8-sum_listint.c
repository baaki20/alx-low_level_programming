#include "lists.h"
#include <stdlib.h>

/**
 * sum_listint - Sums all the data of a listint_t linked list
 * @head: Pointer to the head node of the list
 *
 * Return: The sum of the data in the list
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}

