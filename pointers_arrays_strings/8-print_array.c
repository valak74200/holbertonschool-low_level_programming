#include "main.h"
#include <stdio.h>

/**
 * print_array - prints n elements of an array
 * followed by a new line
 * @a: array to be printed
 * @n: numbers of elements to print
 */
void print_array(int *a, int n)

//Déclaration de la fonction print_array qui prend deux paramètres :
//a : un pointeur vers un tableau d'entiers
//n : le nombre d'éléments à imprimer

{
	int i;

//Déclaration de la variable de boucle i.

	for (i = 0; i < n; i++)

//Boucle for qui itère n fois, de 0 à n-1.

	{
		if (i == 0)
			printf("%d", a[i]);
		else
			printf(", %d", a[i]);

//Condition à l'intérieur de la boucle :
//Pour le premier élément (i == 0), imprime juste le nombre.
//Pour les éléments suivants, imprime une virgule et un espace avant le nombre.

	}
	printf("\n");

//Imprime un saut de ligne après avoir imprimé tous les éléments.

}

//En résumé, print_array est une fonction bien conçue pour imprimer un nombre spécifié d'éléments d'un tableau d'entiers. Elle gère correctement le formatage et est efficace dans son exécution. Avec quelques vérifications supplémentaires, elle pourrait être rendue encore plus robuste pour une utilisation dans des environnements variés.
