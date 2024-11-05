#include "main.h"
#include <stdio.h>

/**
 * *_strspn - gets the length of a prefix substring
 * @s: string to evaluate
 * @accept: string containing the list of characters to match in s
 *
 * Return: the number of bytes in the initial segment
 * of s which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{

//Cette ligne déclare la fonction _strspn qui prend deux paramètres :
//s : la chaîne à évaluer
//accept : la chaîne contenant les caractères à rechercher dans s
//La fonction retourne un unsigned int.

	int i, j, f, flag;

//Déclare quatre variables entières utilisées dans la fonction.

	f = 0;

//Initialise f (qui comptera le nombre de caractères correspondants) à 0.

	for (i = 0; s[i] != '\0'; i++)
	{

//Commence une boucle qui parcourt chaque caractère de la chaîne s.

		flag = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{

//Pour chaque caractère de s, parcourt tous les caractères de accept.

			if (s[i] == accept[j])
			{
				f++;
				flag = 1;
			}
		}

//Si le caractère actuel de s correspond à un caractère de accept, incrémente f et met flag à 1.

		if (flag == 0)
		{
			return (f);
		}
	}

//Si après avoir vérifié tous les caractères de accept, aucune correspondance n'est trouvée (flag reste 0), la fonction retourne la valeur actuelle de f.

	return (0);
}

//Si la boucle se termine sans retourner, la fonction retourne 0.
