#include "main.h"
#include <stdio.h>

/**
 * *_strpbrk - searches a string for any of a set of bytes
 * @s: string to search
 * @accept: stringcontaining the bytes to look for
 *
 * Return: pointer to the byte in s that matches one of the bytes in accept
 * or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{

//Cette ligne déclare la fonction _strpbrk qui prend deux paramètres :
//s : la chaîne à rechercher
//accept : la chaîne contenant les caractères à rechercher dans s
//La fonction retourne un pointeur de type char*.

	int i, j;

//Déclare deux variables entières utilisées comme compteurs dans les boucles.

	for (i = 0; *s != '\0'; i++)
	{

//Commence une boucle qui parcourt chaque caractère de la chaîne s jusqu'à ce qu'elle atteigne le caractère nul (fin de la chaîne).

		for (j = 0; accept[j] != '\0'; j++)
		{

//Pour chaque caractère de s, parcourt tous les caractères de accept.

			if (*s == accept[j])
			{
				return (s);
			}
		}

//Si le caractère actuel de s correspond à un caractère de accept, la fonction retourne immédiatement un pointeur vers ce caractère dans s.

		s++;
	}

//Si aucune correspondance n'est trouvée pour le caractère actuel de s, passe au caractère suivant.

	return (NULL);
}

//Si la boucle se termine sans trouver de correspondance, la fonction retourne NULL.
