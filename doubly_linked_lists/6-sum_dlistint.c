#include "lists.h"

/**
 * sum_dlistint - Calculates the sum of all the data (n) of a dlistint_t list
 * @head: A pointer to the head of the dlistint_t list
 *
 * Return: If the list is empty - 0
 *         Otherwise - the sum of all the data
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
