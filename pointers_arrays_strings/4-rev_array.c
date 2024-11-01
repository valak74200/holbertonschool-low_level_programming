#include "main.h"
#include <stdio.h>

/**
 * reverse_array - print an array of integers
 * @a: an array of integers
 * @n: the number of elements to swap
 *
 */
void reverse_array(int *a, int n)

//Déclaration de la fonction reverse_array qui prend deux paramètres :
//a : un pointeur vers un tableau d'entiers
//n : le nombre d'éléments dans le tableau

{
	int i, j, tmp;

//Déclaration des variables locales :
//i : utilisé comme index pour parcourir le tableau depuis le début
//j : utilisé comme index pour parcourir le tableau depuis la fin
//tmp : variable temporaire pour l'échange des éléments

	j = n - 1;

//Initialisation de j à l'index du dernier élément du tableau.

	for (i = 0; i < n / 2; i++)
	{
		tmp = a[i];
		a[i] = a[j];
		a[j--] = tmp;
	}

//Boucle principale qui inverse le tableau :
//Elle s'exécute jusqu'à la moitié du tableau (n / 2).
//À chaque itération :
//tmp stocke temporairement la valeur de a[i]
//a[i] reçoit la valeur de a[j]
//a[j] reçoit la valeur temporaire stockée dans tmp
//j est décrémenté après l'affectation (j--)

}

//En résumé, cette fonction reverse_array est une implémentation efficace et concise pour inverser un tableau d'entiers en place. Elle utilise une technique d'échange symétrique des éléments, ce qui la rend à la fois simple à comprendre et efficace en termes de performance.
