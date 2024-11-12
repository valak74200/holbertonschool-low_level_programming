#include <stdlib.h>
#include "main.h"

/**
 * *array_range - creates an array of integers
 * @min: minimum range of values stored
 * @max: maximum range of values stored and number of elements
 *
 * Return: pointer to the new array
 */
int *array_range(int min, int max)

// C'est la déclaration de la fonction array_range. Elle prend deux entiers comme paramètres (min et max) et retourne un pointeur vers un entier (l'array créé).

{
	int *ptr;
	int i, size;

// Ces lignes déclarent les variables nécessaires : ptr pour stocker le pointeur retourné par malloc(), i pour l'itération, et size pour la taille du tableau à créer.

	if (min > max)
		return (NULL);

// Cette condition vérifie si min est supérieur à max. Si c'est le cas, la fonction retourne NULL car la plage n'est pas valide.

	size = max - min + 1;

// Cette ligne calcule la taille du tableau. +1 est nécessaire car la plage est inclusive (elle inclut à la fois min et max).

	ptr = malloc(sizeof(int) * size);

// Cette ligne alloue la mémoire nécessaire pour le tableau d'entiers.

	if (ptr == NULL)
		return (NULL);

// Si l'allocation de mémoire échoue (ptr est NULL), la fonction retourne NULL.

	for (i = 0; min <= max; i++)
		ptr[i] = min++;

// Cette boucle remplit le tableau avec les valeurs de min à max. À chaque itération, min est incrémenté après avoir été assigné à ptr[i].

	return (ptr);
}

// Enfin, la fonction retourne le pointeur vers le tableau nouvellement créé et rempli.

// Cette fonction crée un tableau d'entiers contenant tous les nombres de min à max inclus. Elle gère correctement les cas d'erreur (min > max, échec d'allocation) et retourne NULL dans ces cas. La taille du tableau est calculée dynamiquement en fonction de min et max, ce qui rend la fonction flexible pour différentes plages de valeurs.
