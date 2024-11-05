#include "main.h"
#include <stdio.h>

/**
 *  _strlen_recursion - returns the length of a string
 * @s: string to calculate the length of
 *
 * Return: length of the string
 */
int _strlen_recursion(char *s)
{

// Cette ligne déclare la fonction _strlen_recursion qui prend un pointeur vers un caractère (une chaîne de caractères) comme paramètre et retourne un entier (la longueur de la chaîne).

	if (*s == '\0')
		return (0);

// C'est le cas de base de la récursion. Si le caractère pointé par s est le caractère nul '\0' (fin de la chaîne), la fonction retourne 0. Cela signifie qu'on a atteint la fin de la chaîne.

	return (1 + _strlen_recursion(s + 1));

// C'est le cas récursif. Si ce n'est pas la fin de la chaîne, la fonction :
// Ajoute 1 (pour compter le caractère actuel)
// Fait un appel récursif avec le pointeur vers le caractère suivant (s + 1)
// Retourne la somme de ces deux valeurs

}

// Cette approche récursive est élégante et concise. Elle démontre bien comment la récursion peut être utilisée pour décomposer un problème en sous-problèmes plus simples. Chaque appel récursif traite un caractère et délègue le reste de la chaîne à l'appel suivant.
// Cependant, il faut noter que pour de très longues chaînes, cette méthode pourrait causer un dépassement de pile (stack overflow) en raison de la profondeur de la récursion. Dans la pratique, une approche itérative pourrait être plus efficace pour de très longues chaînes.
