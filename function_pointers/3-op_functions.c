#include "3-calc.h"

/**
 * op_add - calculate the sum of two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

// Cette fonction op_add prend deux entiers a et b comme paramètres et retourne leur somme.

/**
 * op_sub - calculates the difference of two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: difference of a and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

// op_sub(int a, int b) : retourne la différence entre a et b (a - b).

/**
 * op_mul - calculates the product of two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: product of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

// op_mul(int a, int b) : retourne le produit de a et b (a * b).

/**
 * op_div - calculates the division of two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: result of the division of a and b
 */
int op_div(int a, int b)
{
	return (a / b);
}

// op_div(int a, int b) : retourne le résultat de la division de a par b (a / b).

/**
 * op_mod - calculates the remainder of the division of two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: remainder of  a divided b
 */
int op_mod(int a, int b)
{
	return (a % b);
}

// op_mod(int a, int b) : retourne le reste de la division de a par b (a % b).

//En résumé, ce fichier définit cinq fonctions arithmétiques de base qui seront probablement utilisées en conjonction avec la fonction get_op_func que nous avons vue précédemment pour créer une calculatrice simple.
