#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node
 *                            to a dlistint_t list at a given position
 * @h: A pointer to the address of the head of the dlistint_t list
 * @idx: The index of the dlistint_t list where the new node should be added
 *       - indices start at 0
 * @n: The integer for the new node to contain.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new node.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *copy = *h;
	unsigned int node;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	if (idx == 0)
	{
		new->next = copy;
		*h = new;
		return (new);
	}

	for (node = 0; node < (idx - 1); node++)
	{
		if (copy == NULL || copy->next == NULL)
			return (NULL);

		copy = copy->next;
	}

	new->next = copy->next;
	copy->next = new;

	return (new);
}
