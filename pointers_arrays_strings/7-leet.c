#include "main.h"
#include <stdio.h>

/**
 * *leet - encodes a string into 1337
 * @s: string to be encoded
 *
 * Return: the resulting string
 */
char *leet(char *s)

//Déclaration de la fonction leet qui prend un pointeur vers une chaîne de caractères et retourne un pointeur vers une chaîne de caractères.

{
	int i, j;

//Déclaration des variables de boucle i et j.

	char *a = "aAeEoOtTlL";
	char *b = "4433007711";

//Définition de deux chaînes de caractères :
//a contient les lettres à remplacer (en minuscules et majuscules).
//b contient les caractères de remplacement correspondants.

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (s[i] == a[j])
			{
				s[i] = b[j];
			}
		}
	}

//Boucles imbriquées :
//La boucle externe parcourt chaque caractère de la chaîne d'entrée s.
//La boucle interne compare chaque caractère de s avec les caractères dans a.
//Si une correspondance est trouvée, le caractère dans s est remplacé par le caractère correspondant dans b.

	return (s);

//Retourne le pointeur vers la chaîne modifiée.

}

//En résumé, leet est une fonction efficace pour encoder une chaîne en "leet speak". Elle est simple à comprendre et à utiliser, bien qu'elle puisse bénéficier de quelques optimisations mineures pour des cas d'utilisation plus larges ou des performances accrues.
