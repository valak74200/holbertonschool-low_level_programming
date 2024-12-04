#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - Prints all the elements of a listint_t list
 * @h: Pointer to the head of the list_t list
 *
 * Return: The number of nodes in the list_t list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (nodes);
}
