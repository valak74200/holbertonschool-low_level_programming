#include <stdio.h>
#include "main.h"

/**
 * print_diagsums - prints the sum of the two diagonals
 * of a square matrix of integers
 * @a: square matrix of which we print the sum of diagonals
 * @size: size of the matrix
 */
void print_diagsums(int *a, int size)
{

//Cette fonction prend deux paramètres :
//a : un pointeur vers un tableau d'entiers (représentant une matrice carrée)
//size : la taille de la matrice carrée
//La fonction ne retourne rien (void).

	int i;

	unsigned int sum, sum1;

//Déclare les variables :
//i pour l'itération
//sum et sum1 pour stocker les sommes des diagonales (non signées pour éviter les dépassements négatifs)

	sum = 0;
	sum1 = 0;

//Initialise les deux sommes à zéro.

	for (i = 0; i < size; i++)
	{

//Commence une boucle qui itère size fois.

		sum += a[(size * i) + i];

//Ajoute à sum l'élément de la diagonale principale.
//L'index (size * i) + i correspond à l'élément (i,i) dans une matrice 2D.

		sum1 += a[(size * (i + 1)) - (i + 1)];

//Ajoute à sum1 l'élément de la diagonale secondaire.
//L'index (size * (i + 1)) - (i + 1) correspond à l'élément (i, size-1-i) dans une matrice 2D.

	}

	printf("%d, %d\n", sum, sum1);
}

//Après la boucle, imprime les deux sommes séparées par une virgule et un espace, suivies d'un saut de ligne.
