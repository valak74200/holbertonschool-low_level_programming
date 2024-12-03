#include <stdlib.h>
#include "function_pointers.h"

/**
 * print_name - prints a name
 * @name: name to print
 * @f: pointer to the printing function
 */
void print_name(char *name, void (*f)(char *))

// C'est la déclaration de la fonction print_name. Elle prend deux paramètres :
// name : un pointeur vers une chaîne de caractères (le nom à imprimer)
// f : un pointeur vers une fonction qui prend un char * comme argument et ne retourne rien (void)

{
	if (name == NULL && f == NULL)
		return;

// Cette condition vérifie si à la fois name et f sont NULL. Si c'est le cas, la fonction se termine immédiatement.

	f(name);
}

// Cette ligne appelle la fonction pointée par f, en lui passant name comme argument.

// En résumé, cette fonction :
// Prend un nom et un pointeur vers une fonction comme arguments.
// Vérifie (ou devrait vérifier) si l'un des arguments est NULL, auquel cas elle ne fait rien.
// Si les arguments sont valides, elle appelle la fonction pointée par f avec name comme argument.
