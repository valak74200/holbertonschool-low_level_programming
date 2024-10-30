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
	int i, j;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
	i++;

	while (src[j] != '\0' && j < n)
	{
		dest[i + j] = src[i];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}
