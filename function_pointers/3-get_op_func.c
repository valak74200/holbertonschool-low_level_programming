#include "3-calc.h"

/**
 * get_op_func - function pointer that selects the correct function to perform
 * the operation asked by the user
 * @s: the operator given by the user
 *
 * Return: pointer to the function that corresponds to the
 * operator given as a parameter
 */
int (*get_op_func(char *s))(int, int)

// C'est la déclaration de la fonction get_op_func. Elle prend une chaîne de caractères comme argument et retourne un pointeur vers une fonction qui prend deux entiers comme arguments et retourne un entier.

{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};

// Cette partie initialise un tableau de structures op_t (défini dans le fichier d'en-tête). Chaque élément du tableau associe un opérateur (sous forme de chaîne) à la fonction correspondante.

	int i;

	i = 0;

// Ces lignes déclarent et initialisent un compteur i qui sera utilisé dans la boucle suivante.

	while (ops[i].op)
	{

// Cette boucle while continue tant que l'opérateur à l'index i n'est pas NULL.

		if (strcmp(ops[i].op, s) == 0)
			return (ops[i].f);

// Cette condition compare l'opérateur à l'index i avec l'opérateur fourni s. Si ils sont identiques, la fonction retourne le pointeur de fonction correspondant.

		i++;
	}

// Si l'opérateur ne correspond pas, on incrémente i pour passer à l'élément suivant du tableau.

	return (NULL);
}

// Si aucun opérateur correspondant n'est trouvé après avoir parcouru tout le tableau, la fonction retourne NULL.

// En résumé, cette fonction prend un opérateur sous forme de chaîne de caractères, le compare avec une liste prédéfinie d'opérateurs, et retourne un pointeur vers la fonction correspondante si une correspondance est trouvée. Si aucune correspondance n'est trouvée, elle retourne NULL. C'est une implémentation du patron de conception "Table de dispatch", utilisé pour sélectionner dynamiquement une fonction basée sur une entrée.
