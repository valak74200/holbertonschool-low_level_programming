#include "variadic_functions.h"

/**
 * print_numbers - prints numbers given as parameters
 * @separator: string to be printed between numbers
 * @n: number of integers passed to the function
 */
void print_numbers(const char *separator, const unsigned int n, ...)

// C'est la déclaration de la fonction print_numbers. Elle prend un séparateur (chaîne de caractères), un nombre n d'arguments à imprimer, et un nombre variable d'arguments (indiqué par ...).

{
	unsigned int i;
	va_list list;

// Ces lignes déclarent les variables locales : i pour l'itération et list pour accéder aux arguments variables.	

	va_start(list, n);

// Cette macro initialise list pour qu'elle pointe sur le premier argument variable.

	for (i = 0; i < n; i++)
	{

// Cette boucle itère n fois, une fois pour chaque nombre à imprimer.
		
		if (!separator)
			printf("%d", va_arg(list, int));
		else if (separator && i == 0)
			printf("%d", va_arg(list, int));
		else
			printf("%s%d", separator, va_arg(list, int));
	}


// Ce bloc conditionnel gère l'impression des nombres et du séparateur :
// Si separator est NULL, il imprime juste le nombre.
// Si separator n'est pas NULL et que c'est le premier nombre (i == 0), il imprime juste le nombre.
// Sinon, il imprime le séparateur suivi du nombre.
// Dans tous les cas, va_arg(list, int) est utilisé pour obtenir le prochain argument de type int.	

	va_end(list);

// Cette macro nettoie la liste d'arguments variables.

	printf("\n");
}

// Enfin, la fonction imprime un retour à la ligne et se termine.

// En résumé, cette fonction print_numbers imprime une série de nombres, séparés par une chaîne spécifiée (si elle n'est pas NULL). Elle utilise des fonctions variadiques pour accepter un nombre variable d'arguments.

