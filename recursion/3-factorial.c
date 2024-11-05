#include "main.h"
#include <stdio.h>

/**
 * factorial - returns the factorial of a number
 * @n: number to return the factorial from
 *
 * Return: factorial of n
 */
int factorial(int n)
{

// Cette ligne déclare la fonction factorial qui prend un entier n comme paramètre et retourne un entier (le résultat du calcul de la factorielle).

	if (n < 0)
		return (-1);

// C'est une vérification de cas spécial. Si n est négatif, la fonction retourne -1, car la factorielle n'est pas définie pour les nombres négatifs. C'est une façon courante de signaler une erreur.

	if (n == 0)
		return (1);

// C'est le cas de base de la récursion. La factorielle de 0 est définie comme étant 1. C'est aussi le point d'arrêt de la récursion.

	return (n * factorial(n - 1));

// C'est le cas récursif. Pour tout nombre positif, la fonction retourne n multiplié par la factorielle de n-1.

}

// Dans la pratique, pour calculer des factorielles de grands nombres, on pourrait utiliser une approche itérative ou des techniques de programmation dynamique pour plus d'efficacité et pour éviter les problèmes de dépassement de pile.
