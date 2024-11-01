#include <stdio.h>
#include "main.h"

/**
 * _strcmp - compare two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)

//Déclaration de la fonction _strcmp. Elle prend deux paramètres (deux chaînes de caractères à comparer) et retourne un entier.

{
	while (*s1 == *s2)
	{

//Début de la boucle while. Elle continue tant que les caractères pointés par s1 et s2 sont égaux.

		if (*s1 == '\0')
		{
			return (0);
		}

//Si on atteint la fin de s1 (et donc aussi de s2 puisqu'ils sont égaux jusqu'ici), les chaînes sont identiques, donc on retourne 0.

		s1++;
		s2++;
	}

//On avance les pointeurs s1 et s2 pour comparer les caractères suivants.

	return (*s1 - *s2);

//Si on sort de la boucle, cela signifie qu'on a trouvé une différence. On retourne la différence entre les valeurs ASCII des caractères différents.

}

//En résumé, cette fonction _strcmp compare deux chaînes de caractères et retourne :
//0 si les chaînes sont identiques
//Une valeur négative si s1 est "inférieure" à s2 (selon l'ordre ASCII)
//Une valeur positive si s1 est "supérieure" à s2 (selon l'ordre ASCII)
//C'est une implémentation personnalisée de la fonction standard strcmp de la bibliothèque string.h.

