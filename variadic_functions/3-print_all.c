#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)

// C'est la déclaration de la fonction print_all. Elle prend une chaîne de format et un nombre variable d'arguments.

{
	int i = 0;
	char *str, *sep = "";

	va_list list;

// Ces lignes déclarent les variables locales : i pour l'itération, str pour stocker les chaînes, sep pour le séparateur (initialisé à une chaîne vide), et list pour accéder aux arguments variables.	

	va_start(list, format);

// Cette macro initialise list pour qu'elle pointe sur le premier argument variable.

	if (format)
	{
		while (format[i])
		{

// Ces lignes vérifient si format n'est pas NULL, puis commencent une boucle qui continue tant qu'il y a des caractères dans format.

			switch (format[i])
			{

// Ce switch examine chaque caractère de format.

				case 'c':
					printf("%s%c", sep, va_arg(list, int));
					break;
				case 'i':
					printf("%s%d", sep, va_arg(list, int));
					break;
				case 'f':
					printf("%s%f", sep, va_arg(list, double));
					break;
				case 's':
					str = va_arg(list, char *);
					if (!str)
						str = "(nil)";
					printf("%s%s", sep, str);
					break;
				default:
				i++;
			continue;

// Chaque case gère un type différent : 'c' pour char, 'i' pour int, 'f' pour float, et 's' pour string. Pour chaque type, il imprime le séparateur suivi de la valeur. Pour les chaînes, il gère le cas NULL. Si le caractère n'est pas reconnu, il passe au suivant.

			}
		sep = ", ";
	i++;
		}
	}

// Après chaque impression réussie, le séparateur est mis à ", " pour les prochaines impressions, et l'index est incrémenté.

printf("\n");
va_end(list);
}

// Enfin, la fonction imprime un retour à la ligne et nettoie la liste d'arguments variables.

// En résumé, cette fonction print_all est très flexible. Elle peut imprimer une série de valeurs de différents types (char, int, float, string) en fonction d'une chaîne de format fournie. Les valeurs sont séparées par ", " après la première impression.
