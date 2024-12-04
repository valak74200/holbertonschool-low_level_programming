#include "lists.h"
#include <stdio.h>

/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list
 * @head: A pointer to the address of the head of the dlistint_t list
 * @n: The integer for the new node
 *
 * Return: If the function fails - NULL
 *         Otherwise - The address of the new element
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;

	*head = new;

	return (new);
}
