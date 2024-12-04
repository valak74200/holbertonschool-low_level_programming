#include "lists.h"

/**
 * get_dnodeint_at_index - Locates a given node of a dlistint_t linked list
 * @head: A pointer to the head of the dlistint_t list
 * @index: The index of the node to locate - indices start at 0
 *
 * Return: If the node does not exist - NULL
 *         Otherwise - the located node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int node;

	for (node = 0; node < index; node++)
	{
		if (head == NULL)
			return (NULL);

		head = head->next;
	}

	return (head);
}
