#include <stdlib.h>
#include "main.h"

/**
 * *_calloc - allocates memory for an array
 * @nmemb: number of elements in the array
 * @size: size of each element
 *
 * Return: pointer to allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)

// C'est la déclaration de la fonction _calloc. Elle prend deux entiers non signés comme paramètres (le nombre d'éléments et la taille de chaque élément) et retourne un pointeur void * (un pointeur générique).

{
	void *ptr;
	unsigned int i;
	unsigned char *p;

// Ces lignes déclarent les variables nécessaires : ptr pour stocker le pointeur retourné par malloc(), i pour l'itération, et p pour parcourir la mémoire allouée octet par octet.

	if (nmemb == 0 || size == 0)
		return (NULL);

// Cette condition vérifie si le nombre d'éléments ou la taille est 0. Si c'est le cas, la fonction retourne NULL.

	ptr = malloc(size * nmemb);

// Cette ligne alloue la mémoire nécessaire en multipliant le nombre d'éléments par la taille de chaque élément.

	if (ptr == NULL)
		return (NULL);

// Si l'allocation de mémoire échoue (ptr est NULL), la fonction retourne NULL.

	p = (unsigned char *)ptr;

// Cette ligne convertit le pointeur void * en unsigned char *. Cela permet de parcourir la mémoire octet par octet.

	for (i = 0; i < nmemb * size; i++)
		p[i] = 0;

// Cette boucle initialise chaque octet de la mémoire allouée à 0. C'est ce qui différencie _calloc de malloc : _calloc initialise la mémoire à zéro, tandis que malloc ne le fait pas.

	return (ptr);
}

// Enfin, la fonction retourne le pointeur vers la mémoire allouée et initialisée.

// Cette fonction est une implémentation personnalisée de la fonction calloc() de la bibliothèque standard C. Elle alloue de la mémoire pour un tableau et initialise tous les octets à zéro. La différence principale avec malloc() est cette initialisation à zéro. Cette implémentation gère correctement les cas d'erreur et effectue l'initialisation manuellement.
