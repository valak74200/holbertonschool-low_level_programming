#include "main.h"
#include <stdio.h>

/**
 * _pow_recursion - returns the value of x raised to the power of y
 * @x: value to raise
 * @y: power
 *
 * Return: result of the power
 */
int _pow_recursion(int x, int y)
{

// Cette ligne déclare la fonction _pow_recursion qui prend deux entiers comme paramètres :
// x : la base
// y : l'exposant
// La fonction retourne un entier (le résultat de x^

	if (y < 0)
		return (-1);

// C'est une vérification de cas spécial. Si l'exposant est négatif, la fonction retourne -1. C'est une façon de signaler que la fonction ne gère pas les exposants négatifs.

	if (y == 0)
		return (1);

// C'est le cas de base de la récursion. Tout nombre élevé à la puissance 0 est égal à 1. C'est aussi le point d'arrêt de la récursion.

	return (x * _pow_recursion(x, y - 1));

// C'est le cas récursif. Pour tout exposant positif, la fonction retourne x multiplié par le résultat de x^(y-1).

}

// Pour une implémentation plus efficace, on pourrait utiliser l'exponentiation rapide (aussi appelée exponentiation par carré), qui réduit considérablement le nombre d'opérations nécessaires, surtout pour de grands exposants.
