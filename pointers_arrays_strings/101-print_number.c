#include "main.h"
#include <stdio.h>

/**
 * print_number - prints an integer
 * @n: integer to be printed
 */
void print_number(int n)

//Déclaration de la fonction print_number qui prend un entier n comme argument et ne retourne rien (void).

{
	unsigned int n1;

//Déclaration d'une variable non signée n1. Elle sera utilisée pour gérer les nombres négatifs sans risque de dépassement.

	if (n < 0)
	{
		n1 = -n;
		_putchar('-');
	} else
	{
		n1 = n;
	}

//Gestion des nombres négatifs :
//Si n est négatif, n1 prend la valeur absolue de n et un signe moins est imprimé.
//Sinon, n1 prend simplement la valeur de n.
//L'utilisation de unsigned int pour n1 permet de gérer correctement la valeur absolue de INT_MIN.

	if (n1 / 10)
		print_number(n1 / 10);

//Appel récursif de la fonction :
//Si n1 divisé par 10 n'est pas zéro (c'est-à-dire si n1 a plus d'un chiffre), la fonction s'appelle récursivement avec n1 / 10.
//Cela permet de traiter les chiffres de gauche à droite.

	_putchar((n1 % 10) + '0');

//Impression du chiffre le plus à droite :
//n1 % 10 donne le chiffre le plus à droite.
//Ajouter '0' convertit la valeur numérique en son caractère ASCII correspondant.
//_putchar est probablement une fonction personnalisée pour imprimer un seul caractère.

}

//En résumé, cette fonction print_number est une implémentation efficace et élégante pour imprimer des entiers sans utiliser les fonctions standard de la bibliothèque C. Elle gère correctement les cas particuliers comme les nombres négatifs et utilise la récursion de manière judicieuse pour traiter les nombres multi-chiffres.
