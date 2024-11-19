#include "variadic_functions.h"

/**
 * sum_them_all - calculates the sum of all parameters
 * @n: number of arguments passed to the function
 *
 * Return: the resulting sum
 */
int sum_them_all(const unsigned int n, ...)

// C'est la déclaration de la fonction sum_them_all. Elle prend un paramètre n qui indique le nombre d'arguments variables, et les points de suspension ... indiquent que la fonction peut accepter un nombre variable d'arguments.

{
	unsigned int i;
	int sum = 0;
	va_list list;

// Ces lignes déclarent les variables locales :
// i pour l'itération
// sum pour stocker la somme, initialisée à 0
// list de type va_list pour accéder aux arguments variables

        va_start(list, n);

// Cette macro initialise list pour qu'elle pointe sur le premier argument variable. n est le dernier paramètre nommé avant les arguments variables.

	for (i = 0; i < n; i++)
		sum += va_arg(list, int);

// Cette boucle itère n fois. À chaque itération, elle utilise va_arg pour récupérer le prochain argument de type int de la liste et l'ajoute à sum.

	va_end(list);

// Cette macro nettoie la liste d'arguments variables.

	return (sum);
}

// La fonction retourne la somme calculée.

// En résumé, cette fonction sum_them_all est une fonction variadique qui prend un nombre variable d'arguments entiers, les additionne tous, et retourne la somme. Le premier argument n spécifie combien d'arguments supplémentaires suivent.
