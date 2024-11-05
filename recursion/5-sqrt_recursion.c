#include "main.h"
#include <stdio.h>

int actual_sqrt_recursion(int n, int i);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to calculate the square root of
 *
 * Return: the resulting square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (actual_sqrt_recursion(n, 0));
}

// Cette fonction sert de point d'entrée.
// Elle vérifie d'abord si n est négatif. Si oui, elle retourne -1 car les nombres négatifs n'ont pas de racine carrée réelle.
// Si n n'est pas négatif, elle appelle la fonction auxiliaire actual_sqrt_recursion avec n et une valeur initiale de 0 pour l'itérateur.

/**
 * actual_sqrt_recursion - recurses to find the natural
 * square root of a number
 * @n: number to calculate the sqaure root of
 * @i: iterator
 *
 * Return: the resulting square root
 */
int actual_sqrt_recursion(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (actual_sqrt_recursion(n, i + 1));
}

// Cette fonction fait le vrai travail de calcul de la racine carrée.
// Elle prend deux paramètres : n (le nombre dont on cherche la racine carrée) et i (l'itérateur actuel).
// Il y a trois cas possibles :
// Si i² > n, cela signifie qu'il n'y a pas de racine carrée naturelle, donc elle retourne -1.
// Si i² == n, cela signifie que i est la racine carrée exacte, donc elle retourne i.
// Si aucun des cas ci-dessus n'est vrai, elle s'appelle récursivement avec i + 1.

// Pour améliorer l'efficacité, on pourrait utiliser une approche de recherche binaire ou la méthode de Newton-Raphson, qui convergeraient plus rapidement vers la solution, surtout pour de grands nombres.
