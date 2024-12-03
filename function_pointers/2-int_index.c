#include "function_pointers.h"
#include <stdlib.h>

/**
 * int_index - earches for an integer
 * @array: array to search in
 * @size: size of the array
 * @cmp: pointer to the comparing function
 *
 * Return: index of the first element for which
 * the cmp function does not return 0, or -1 if no match is found
 * or size is negative
 */
int int_index(int *array, int size, int (*cmp)(int))

// C'est la déclaration de la fonction int_index. Elle prend trois paramètres :
// int *array : un pointeur vers un tableau d'entiers
// int size : la taille du tableau
// int (*cmp)(int) : un pointeur vers une fonction qui prend un int comme argument et retourne un int


{
	int i;

// Cette ligne déclare une variable entière i qui sera utilisée comme compteur dans la boucle.

	if (array && cmp)
	{

// Cette condition vérifie si à la fois le tableau et le pointeur de fonction ne sont pas NULL. Si l'un des deux est NULL, le code à l'intérieur de ce bloc ne sera pas exécuté.

		for (i = 0; i < size; i++)
		{

// C'est une boucle for qui itère sur chaque élément du tableau.

			if (cmp(array[i]) != 0)
				return (i);

// Pour chaque élément, la fonction pointée par cmp est appelée avec l'élément actuel du tableau comme argument. Si cette fonction retourne une valeur différente de 0, la fonction int_index retourne immédiatement l'index actuel i.

		}
	}

	return (-1);

// Si aucun élément ne satisfait la condition (c'est-à-dire si cmp retourne toujours 0), ou si array ou cmp sont NULL, ou si size est 0 ou négatif, la fonction retourne -1.

}

// En résumé, cette fonction cherche dans un tableau le premier élément pour lequel une fonction de comparaison donnée retourne une valeur non nulle. Elle retourne l'index de cet élément, ou -1 si aucun élément ne satisfait la condition ou si les paramètres d'entrée ne sont pas valides.
