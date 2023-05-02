#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list, safely
 * @head: pointer to the head node of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	size_t count = 0, loop_start = 0;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		count++;

		if (slow == fast)
		{
			printf("Loop detected\n");
			loop_start = count;
			break;
		}
	}

	count = 0;
	while (head && (!loop_start || count < loop_start))
	{
		printf("%d\n", head->n);
		head = head->next;
		count++;
	}

	if (loop_start)
		printf("-> [Loop back to node %lu]\n", loop_start);

	return (count);
}

