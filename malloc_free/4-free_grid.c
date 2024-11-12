#include <stdlib.h>
#include "main.h"

/**
 * free_grid - frees the memory allocate for the grid
 * created by alloc_grid()
 * @grid: grid to free
 * @height: height of the grid
 */
void free_grid(int **grid, int height)

// C'est la déclaration de la fonction free_grid. Elle prend deux paramètres : un pointeur vers un pointeur d'entiers (grid) et un entier (height). La fonction ne retourne rien (void).

{
	int i;

// Cette ligne déclare une variable entière i qui sera utilisée pour l'itération.

	if (grid == NULL || height == 0)
		return;

// Cette condition vérifie si grid est NULL ou si height est 0. Si l'une de ces conditions est vraie, la fonction se termine immédiatement sans rien faire. C'est une vérification de sécurité pour éviter de tenter de libérer une mémoire non allouée ou invalide.

	for (i = 0; i < height; i++)
		free(grid[i]);

// Cette boucle parcourt chaque ligne de la grille et libère la mémoire allouée pour chaque ligne. Rappelez-vous que dans une grille 2D allouée dynamiquement, chaque ligne est un tableau d'entiers alloué séparément.

	free(grid);

// Après avoir libéré toutes les lignes, cette ligne libère la mémoire allouée pour le tableau de pointeurs qui représentait les lignes de la grille.

}

// Cette fonction est conçue pour libérer correctement la mémoire allouée par une fonction comme alloc_grid() que nous avons vue précédemment. Elle libère d'abord chaque ligne individuellement, puis le tableau de pointeurs vers ces lignes. Cette approche est nécessaire pour éviter les fuites de mémoire lors de la manipulation de tableaux 2D alloués dynamiquement.
