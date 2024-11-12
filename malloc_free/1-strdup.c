#include "main.h"
#include <stdlib.h>

/**
 * _strdup - copies the string given as parameter
 * @str: string to duplicate
 *
 * Return: pointer to the copied string (Success), NULL (Error)
 */
char *_strdup(char *str)

// C'est la déclaration de la fonction _strdup. Elle prend un pointeur vers une chaîne de caractères comme paramètre et retourne un pointeur vers une chaîne de caractères.

{
	char *dup;
	unsigned int i, len;

// Ces lignes déclarent un pointeur dup qui sera utilisé pour stocker la copie de la chaîne, et deux variables entières non signées i et len pour l'itération et la longueur de la chaîne.

	i = 0;
	len = 0;

// Initialisation des variables i et len à 0.

	if (str == NULL)
		return (NULL);

// Si la chaîne d'entrée est NULL, la fonction retourne NULL immédiatement.

	while (str[len])
		len++;

// Cette boucle calcule la longueur de la chaîne d'entrée.

	dup = malloc(sizeof(char) * (len + 1));

// Cette ligne alloue dynamiquement de la mémoire pour la nouvelle chaîne. La taille allouée est (len + 1) * sizeof(char) pour inclure le caractère nul de fin.

	if (dup == NULL)
		return (NULL);

// Si l'allocation de mémoire a échoué (dup est NULL), la fonction retourne NULL.

	while ((dup[i] = str[i]) != '\0')
		i++;

// Cette boucle copie chaque caractère de str dans dup, y compris le caractère nul de fin. La condition de la boucle effectue l'affectation et vérifie si le caractère copié est '\0'.

	return (dup);
}

// Enfin, la fonction retourne le pointeur vers la nouvelle chaîne dupliquée.
