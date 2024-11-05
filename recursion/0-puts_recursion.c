#include "main.h"

/**
 * _puts_recursion - print a string followed by a new line
 * @s: string to print
 */
void _puts_recursion(char *s)
{

// Cette ligne déclare la fonction _puts_recursion qui prend un pointeur vers un caractère (une chaîne de caractères) comme paramètre et ne retourne rien (void).

	if (*s == '\0')
	{

// Cette ligne vérifie si le caractère pointé par s est le caractère nul '\0'. C'est le cas de base de la récursion, indiquant la fin de la chaîne.

		_putchar('\n');

// Si c'est la fin de la chaîne, cette ligne imprime un saut de ligne.

		return;

// Cette ligne termine l'exécution de la fonction si c'était la fin de la chaîne

	}
	_putchar(*s);

// Si ce n'était pas la fin de la chaîne, cette ligne imprime le caractère actuel pointé par s.

	_puts_recursion(s + 1);

// Cette ligne est l'appel récursif. Elle appelle la même fonction avec le pointeur vers le caractère suivant (s + 1).

}

// Cette approche récursive "dépile" les appels de fonction dans l'ordre inverse, ce qui permet d'imprimer les caractères dans le bon ordre, suivis d'un seul saut de ligne à la fin.
