#include "main.h"
#include <stdio.h>

/**
 * *_strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to look for
 *
 * Return: pointer to the beginning of the located substring
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{

//Cette ligne déclare la fonction _strstr qui prend deux paramètres :
//haystack : la chaîne principale dans laquelle chercher
//needle : la sous-chaîne à rechercher
//La fonction retourne un pointeur de type char*

	int i, j;

//Déclare deux variables entières utilisées comme compteurs dans les boucles.

	for (i = 0; haystack[i] != '\0'; i++)
	{

//Commence une boucle qui parcourt chaque caractère de la chaîne haystack.

		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}

//Pour chaque position dans haystack, cette boucle compare les caractères suivants avec ceux de needle. Si une différence est trouvée, la boucle s'arrête.

		if (!needle[j])
			return (&haystack[i]);
	}

//Si la boucle interne s'est terminée parce que tous les caractères de needle ont été trouvés (c'est-à-dire que needle[j] est le caractère nul), la fonction retourne un pointeur vers le début de la sous-chaîne trouvée dans haystack.

	return (NULL);
}

//Si la boucle se termine sans trouver de correspondance, la fonction retourne NULL.
