#include "main.h"
#include <stdio.h>

/**
 * *_strncat - concatenates two strings
 * @src: string to add
 * @dest: string to append do
 * @n: number of bytes of str to concatenate
 *
 * Return: a pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len = 0;
	int i;

	while (dest[dest_len] != '\0')
		dest_len++;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

			if (i < n)
				dest[dest_len = i] = '\0';

	return (dest);
}
