#include "main.h"

/**
 * _print_rev_recursion - prints a string in reverse
 * @s: string to print
 */
void _print_rev_recursion(char *s)
{

// Cette ligne déclare la fonction _print_rev_recursion qui prend un pointeur vers un caractère (une chaîne de caractères) comme paramètre et ne retourne rien (void).

	if (*s)
	{

// Cette ligne vérifie si le caractère pointé par s n'est pas le caractère nul '\0'. En C, toute valeur non nulle est considérée comme vraie, donc cette condition est vraie tant qu'on n'a pas atteint la fin de la chaîne.

		_print_rev_recursion(s + 1);

// Si ce n'est pas la fin de la chaîne, cette ligne fait un appel récursif à la fonction avec le pointeur vers le caractère suivant (s + 1). C'est la clé de l'inversion : on avance d'abord jusqu'à la fin de la chaîne avant d'imprimer quoi que ce soit.

		_putchar(*s);

// Après l'appel récursif, cette ligne imprime le caractère actuel. C'est ce qui permet d'imprimer la chaîne à l'envers : les caractères sont imprimés dans l'ordre inverse des appels récursifs.

	}
}

// Cette approche est élégante car elle utilise la pile d'appels pour inverser naturellement l'ordre des caractères. La récursion "dépile" les appels de fonction dans l'ordre inverse, ce qui permet d'imprimer les caractères de la fin vers le début.
// C'est un excellent exemple de la puissance et de l'élégance de la récursion pour résoudre certains problèmes de manière concise et intuitive.
