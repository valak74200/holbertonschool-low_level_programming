#include <stdlib.h>
#include "main.h"
#include <stdio.h>

/**
 * *str_concat - concatenates two strings
 * @s1: string to concatenate
 * @s2: other string to concatenate
 *
 * Return: pointer to the new string created (Success), or NULL (Error)
 */
char *str_concat(char *s1, char *s2)

// C'est la déclaration de la fonction str_concat. Elle prend deux pointeurs vers des chaînes de caractères comme paramètres et retourne un pointeur vers une chaîne de caractères.

{
	char *s3;
	unsigned int i = 0, j = 0, len1 = 0, len2 = 0;

// Ces lignes déclarent un pointeur s3 qui sera utilisé pour stocker la chaîne concaténée, et quatre variables entières non signées i, j, len1, et len2 pour l'itération et les longueurs des chaînes.Ces lignes déclarent un pointeur s3 qui sera utilisé pour stocker la chaîne concaténée, et quatre variables entières non signées i, j, len1, et len2 pour l'itération et les longueurs des chaînes.

	while (s1 && s1[len1])
		len1++;
	while (s2 && s2[len2])
		len2++;

// Ces boucles calculent les longueurs de s1 et s2. La condition s1 && s1[len1] vérifie si s1 n'est pas NULL et si le caractère actuel n'est pas '\0'.

	s3 = malloc(sizeof(char) * (len1 + len2 + 1));
	if (s3 == NULL)
		return (NULL);

// Ces lignes allouent dynamiquement de la mémoire pour s3. La taille allouée est (len1 + len2 + 1) * sizeof(char) pour inclure le caractère nul de fin. Si l'allocation échoue, la fonction retourne NULL.

	i = 0;
	j = 0;

// Réinitialisation des variables i et j à 0 pour les utiliser dans les boucles suivantes.

	if (s1)
	{
		while (i < len1)
		{
			s3[i] = s1[i];
			i++;
		}
	}

// Si s1 n'est pas NULL, cette boucle copie tous les caractères de s1 dans s3.

	if (s2)
	{
		while (i < (len1 + len2))
		{
			s3[i] = s2[j];
			i++;
			j++;
		}
	}

// Si s2 n'est pas NULL, cette boucle copie tous les caractères de s2 à la suite de s1 dans s3.

	s3[i] = '\0';

// Cette ligne ajoute le caractère nul de fin à s3.

	return (s3);
}

// Enfin, la fonction retourne le pointeur vers la nouvelle chaîne concaténée s3.
// Cette fonction gère correctement les cas où s1 ou s2 (ou les deux) sont NULL, en les traitant comme des chaînes vides.
