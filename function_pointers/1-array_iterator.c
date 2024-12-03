#include <stdlib.h>
#include "function_pointers.h"

/**
 * array_iterator - executes a function given as a parameter
 * on each element of an array
 * @array: array to iterate over
 * @size: size of the array
 * @action: pointer to function used
 */
void array_iterator(int *array, size_t size, void (*action)(int))

// C'est la déclaration de la fonction array_iterator. Elle prend trois paramètres :
// int *array : un pointeur vers un tableau d'entiers
// size_t size : la taille du tableau
// void (*action)(int) : un pointeur vers une fonction qui prend un int comme argument et ne retourne rien

{
	unsigned int i;

// Cette ligne déclare une variable non signée i qui sera utilisée comme compteur dans la boucle.

	if (array == NULL && action == NULL)
		return;

// Cette condition vérifie si à la fois le tableau et le pointeur de fonction sont NULL. Si c'est le cas, la fonction se termine immédiatement.

	for (i = 0; i < size; i++)
		action(array[i]);

// C'est une boucle for qui itère sur chaque élément du tableau. Pour chaque élément, elle appelle la fonction pointée par action, en passant l'élément actuel du tableau comme argument.

}

//En résumé, cette fonction prend un tableau, sa taille, et un pointeur vers une fonction. Elle applique ensuite cette fonction à chaque élément du tableau. C'est un exemple d'utilisation de pointeurs de fonction pour implémenter un comportement générique sur un tableau.
