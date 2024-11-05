#include "main.h"
#include <stdio.h>

int actual_prime(int n, int i);

/**
 * is_prime_number - says if an integer is a prime number or not
 * @n: number to evaluate
 *
 * Return: 1 if n is a prime number, 0 if not
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (actual_prime(n, n - 1));
}

// Cette fonction sert de point d'entrée.
// Elle vérifie d'abord si n est inférieur ou égal à 1. Si oui, elle retourne 0 car les nombres inférieurs ou égaux à 1 ne sont pas premiers.
// Si n est supérieur à 1, elle appelle la fonction auxiliaire actual_prime avec n et n-1 comme arguments.

/**
 * actual_prime - calculates if a number is prime recursively
 * @n: number to evaluate
 * @i: iterator
 *
 * Return: 1 if n is prime, 0 if not
 */
int actual_prime(int n, int i)
{
	if (i == 1)
		return (1);
	if (n % i == 0 && i > 0)
		return (0);
	return (actual_prime(n, i - 1));
}

// Cette fonction fait le vrai travail de vérification de la primalité.
// Elle prend deux paramètres : n (le nombre à vérifier) et i (l'itérateur actuel, commençant à n-1).
// Il y a trois cas possibles :
// Si i est devenu 1, cela signifie qu'aucun diviseur autre que 1 et n lui-même n'a été trouvé, donc le nombre est premier et la fonction retourne 1.
// Si n est divisible par i (et i > 0), alors n n'est pas premier et la fonction retourne 0.
// Si aucun des cas ci-dessus n'est vrai, elle s'appelle récursivement avec i - 1.

// Malgré ces limitations, cette implémentation est une bonne démonstration de l'utilisation de la récursion pour résoudre ce type de problème, et elle fonctionne correctement pour les petits nombres.
