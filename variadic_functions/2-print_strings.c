#include "variadic_functions.h"

/**
 * print_strings - prints strings
 * @separator: separator between strings
 * @n: number of arguments
 */
void print_strings(const char *separator, const unsigned int n, ...)

// C'est la déclaration de la fonction print_strings. Elle prend un séparateur (chaîne de caractères), un nombre n d'arguments à imprimer, et un nombre variable d'arguments (indiqué par ...).

{
	unsigned int i;
	char *str;

	va_list list;

// Ces lignes déclarent les variables locales : i pour l'itération, str pour stocker chaque chaîne, et list pour accéder aux arguments variables.

	va_start(list, n);

// Cette macro initialise list pour qu'elle pointe sur le premier argument variable.
	
	for (i = 0; i < n; i++)
	{

// Cette boucle itère n fois, une fois pour chaque chaîne à imprimer.
		
		str = va_arg(list, char *);
		if (!str)
			str = "(nil)";

// Ces lignes récupèrent la prochaine chaîne de caractères de la liste d'arguments. Si la chaîne est NULL, elle est remplacée par "(nil)".

		if (!separator)
			printf("%s", str);
		else if (separator && i == 0)
			printf("%s", str);
		else
			printf("%s%s", separator, str);
	}

// Ce bloc conditionnel gère l'impression des chaînes et du séparateur :
// Si separator est NULL, il imprime juste la chaîne.
// Si separator n'est pas NULL et que c'est la première chaîne (i == 0), il imprime juste la chaîne.
// Sinon, il imprime le séparateur suivi de la chaîne.	

	printf("\n");

// Cette ligne imprime un retour à la ligne après avoir imprimé toutes les chaînes.

	va_end(list);
}

// Cette macro nettoie la liste d'arguments variables, et la fonction se termine.

// En résumé, cette fonction print_strings imprime une série de chaînes de caractères, séparées par une chaîne spécifiée (si// elle n'est pas NULL). Elle utilise des fonctions variadiques pour accepter un nombre variable d'arguments.
