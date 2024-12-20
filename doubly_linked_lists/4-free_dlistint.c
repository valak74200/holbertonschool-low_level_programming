#include "lists.h"
#include <stdio.h>

/**
 * free_dlistint - Free a dlistint_t list
 * @head: A pointer to the head of the dlistint_t list to be free
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
