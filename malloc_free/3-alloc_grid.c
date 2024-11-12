#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * **alloc_grid - creates a two dimensional array of ints
 * @width: width of the matrix
 * @height: height of the matrix
 *
 * Return: pointer to the created matrix (Success)
 * or NULL (Error)
 */
int **alloc_grid(int width, int height)

// C'est la déclaration de la fonction alloc_grid. Elle prend deux entiers comme paramètres (width et height) et retourne un pointeur vers un pointeur d'entiers (un tableau 2D).

{
	int **arr;
	int i, j;

// Ces lignes déclarent un pointeur vers un pointeur d'entiers arr (qui sera notre tableau 2D) et deux variables entières i et j pour l'itération.

	if (height <= 0 || width <= 0)
		return (NULL);

// Si la hauteur ou la largeur est inférieure ou égale à 0, la fonction retourne NULL.

	arr = (int **) malloc(sizeof(int *) * height);

// Cette ligne alloue de la mémoire pour un tableau de pointeurs d'entiers. Chaque pointeur représentera une ligne de notre matrice.

	if (arr == NULL)
		return (NULL);

// Si l'allocation de mémoire a échoué, la fonction retourne NULL.

	for (i = 0; i < height; i++)
	{
		arr[i] = (int *) malloc(sizeof(int) * width);
		if (arr[i] == NULL)
		{
			for (j = 0; j <= i; j++)
				free(arr[j]);
			free(arr);
			return (NULL);
		}
	}

// Cette boucle alloue de la mémoire pour chaque ligne de la matrice. Si une allocation échoue, elle libère toute la mémoire précédemment allouée et retourne NULL.

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			arr[i][j] = 0;
		}
	}

// Ces boucles imbriquées initialisent tous les éléments de la matrice à 0.

	return (arr);
}

// Enfin, la fonction retourne le pointeur vers la matrice nouvellement créée et initialisée.
// Ce code crée une matrice 2D dynamiquement allouée, gère correctement les erreurs d'allocation de mémoire, et initialise tous les éléments à 0.

