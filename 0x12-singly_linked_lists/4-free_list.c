#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to the head node of the list
 */
void free_list(list_t *head)
{
	list_t *current_node;

	while (head != NULL)
	{
		/* save a pointer to the current node */
		current_node = head;

		/* move the head pointer to the next node */
		head = head->next;

		/* free the string in the current node */
		free(current_node->str);

		/* free the current node */
		free(current_node);
	}
}

