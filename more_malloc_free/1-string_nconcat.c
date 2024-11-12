#include <stdlib.h>
#include "main.h"

/**
 * *string_nconcat - concatenates n bytes of a string to another string
 * @s1: string to append to
 * @s2: string to concatenate from
 * @n: number of bytes from s2 to concatenate to s1
 *
 * Return: pointer to the resulting string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)

// C'est la déclaration de la fonction string_nconcat. Elle prend deux chaînes de caractères et un entier non signé comme paramètres, et retourne un pointeur vers une chaîne de caractères.

{
	char *s;
	unsigned int i = 0, j = 0, len1 = 0, len2 = 0;

// Ces lignes déclarent les variables nécessaires : s pour la nouvelle chaîne, i et j pour l'itération, len1 et len2 pour les longueurs des chaînes d'entrée.

	while (s1 && s1[len1])
		len1++;
	while (s2 && s2[len2])
		len2++;

// Ces boucles calculent les longueurs de s1 et s2. Elles gèrent aussi le cas où s1 ou s2 pourrait être NULL.

	if (n < len2)
		s = malloc(sizeof(char) * (len1 + n + 1));
	else
		s = malloc(sizeof(char) * (len1 + len2 + 1));

// Cette condition alloue la mémoire pour la nouvelle chaîne. Si n est inférieur à la longueur de s2, on alloue juste assez pour n caractères de s2. Sinon, on alloue pour toute la longueur de s2.

	if (!s)
		return (NULL);

// Si l'allocation échoue, la fonction retourne NULL.

	while (i < len1)
	{
		s[i] = s1[i];
		i++;
	}

// Cette boucle copie tous les caractères de s1 dans la nouvelle chaîne.

	while (n < len2 && i < (len1 + n))
		s[i++] = s2[j++];

// Cette boucle copie jusqu'à n caractères de s2 dans la nouvelle chaîne, à la suite de s1.

	s[i] = '\0';

// Cette ligne ajoute le caractère nul de fin à la nouvelle chaîne.

	return (s);
}

// Enfin, la fonction retourne le pointeur vers la nouvelle chaîne concaténée.

// Cette fonction crée une nouvelle chaîne qui est la concaténation de s1 et des n premiers caractères de s2 (ou de tout s2 si n est plus grand que la longueur de s2). Elle gère correctement les cas où s1 ou s2 sont NULL, les traitant comme des chaînes vides.
