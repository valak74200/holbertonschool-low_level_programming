#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * *create_array - creates an array of chars,
 * and initializes it with a specific char
 * @size: size of the array to create
 * @c: char to initialize the array c
 *
 * Return: pointer to the array (Success), NULL (Error)
 */
char *create_array(unsigned int size, char c)

// C'est la déclaration de la fonction create_array. Elle prend deux paramètres : size (la taille du tableau) et c (le caractère d'initialisation), et retourne un pointeur vers char.

{
	char *p;
	unsigned int i = 0;

// Ces lignes déclarent un pointeur p qui sera utilisé pour stocker l'adresse du tableau, et une variable i pour l'itération, initialisée à 0.

	if (size == 0)
		return (NULL);

// Si la taille demandée est 0, la fonction retourne NULL immédiatement.

	p = (char *) malloc(sizeof(char) * size);

// Cette ligne alloue dynamiquement de la mémoire pour le tableau. La taille allouée est size * sizeof(char).

	if (p == NULL)
		return (0);

// Si l'allocation de mémoire a échoué (p est NULL), la fonction retourne 0.

	while (i < size)
	{
		*(p + i) = c;
		i++;
	}

// Cette boucle initialise chaque élément du tableau avec le caractère c. *(p + i) est équivalent à p[i].

	*(p + i) = '\0';

// Cette ligne ajoute un caractère nul à la fin du tableau, le transformant en une chaîne de caractères C valide.

	return (p);
}

// Enfin, la fonction retourne le pointeur vers le tableau nouvellement créé et initialisé.
