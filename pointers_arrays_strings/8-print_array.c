#include "main.h"
#include <stdio.h>

/**
 * print_array - prints n elements of an array
 * followed by a new line
 * @a: array to be printed
 * @n: numbers of elements to print
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (i == 0)
			printf("%d", a[i]);
		else
			printf(", %d", a[i]);
	}
	printf("\n");
}
