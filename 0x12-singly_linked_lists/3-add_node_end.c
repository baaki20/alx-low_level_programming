#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to a pointer to the head node of the list
 * @str: string to be added to the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *current_node;

	/* allocate memory for new node */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	/* duplicate the string */
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	/* set the length of the string */
	new_node->len = strlen(str);

	/* set the next pointer of the new node to NULL */
	new_node->next = NULL;

	/* if the list is empty, set the head pointer to the new node */
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		/* find the last node in the list */
		current_node = *head;
		while (current_node->next != NULL)
			current_node = current_node->next;

		/* set the next pointer of the last node to the new node */
		current_node->next = new_node;
	}

	/* return the address of the new node */
	return (new_node);
}

