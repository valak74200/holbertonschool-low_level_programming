#include "main.h"
#include <stdio.h>

/**
 * *rot13 - rotate by 13 places
 * @s: string to be encoded
 *
 * Return: the resulting string
 */
char *rot13(char *s)
{
	int i, j;

	i = 0;
	j = 0;

	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char b[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; s[i] != '\0'; i++)
	{

		for (j = 0; a[j] != '\0'; j++)
		{
			if (s[i] == a[j])
			{
				s[i] = b[j];
				break;
			}
		}
	}

	return (s);
}
