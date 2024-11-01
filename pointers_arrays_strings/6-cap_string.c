#include <stdio.h>
#include "main.h"

/**
 * *cap_string - capitalizes all words of a string
 * @s: string to modify
 *
 * Return: the result string
 */
char *cap_string(char *s)

//Déclaration de la fonction qui prend un pointeur vers une chaîne de caractères et retourne un pointeur vers une chaîne de caractères.

{
	int i, j;

//Déclaration des variables de boucle.

	char spe[13] = {' ', '\t', '\n', ',', ';', '.',
		'!', '?', '"', '(', ')', '{', '}'};

//Définition d'un tableau de caractères spéciaux qui sont considérés comme des séparateurs de mots.

	for (i = 0; s[i] != '\0'; i++)

//Boucle principale qui parcourt chaque caractère de la chaîne.

	{
		if (i == 0 && s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;

//Met en majuscule le premier caractère de la chaîne s'il est une lettre minuscule.

		for (j = 0; j < 13; j++)
		{
			if (s[i] == spe[j])
			{
				if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
				{
					s[i + 1] -= 32;
				}
			}
		}
	}

//Boucle interne qui :
//Vérifie si le caractère actuel est un séparateur.
//Si c'est le cas et que le caractère suivant est une lettre minuscule, le convertit en majuscule.

	return (s);

//Retourne le pointeur vers la chaîne modifiée.

}

//En résumé, cap_string est une fonction efficace pour mettre en majuscule le premier caractère de chaque mot dans une chaîne. Elle gère bien une variété de séparateurs de mots, mais pourrait bénéficier de quelques améliorations mineures pour la rendre plus robuste et portable.
