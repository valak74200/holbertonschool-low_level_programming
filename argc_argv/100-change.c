#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - prints the minimum number of coins to
 * make change for an amount of money
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (Success), 1 (Error)
 */
int main(int argc, char *argv[])

// Déclaration de la fonction main avec les paramètres argc (nombre d'arguments) et argv (tableau des arguments).

{
	int num, j, result;
	int coins[] = {25, 10, 5, 2, 1};

// Déclaration des variables locales et initialisation d'un tableau de pièces de monnaie.

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

// Vérifie si le nombre d'arguments est correct (2). Sinon, affiche une erreur et quitte le programme.

	num = atoi(argv[1]);
	result = 0;

// Convertit le deuxième argument en entier et initialise le résultat à 0.

	if (num < 0)
	{
		printf("0\n");
		return (0);
	}

// Si le nombre est négatif, affiche 0 et quitte le programme.

	for (j = 0; j < 5 && num >= 0; j++)
	{
		while (num >= coins[j])
		{
			result++;
			num -= coins[j];
		}
	}

// Boucle à travers les types de pièces et compte combien de chaque pièce est nécessaire pour atteindre le montant.

	printf("%d\n", result);
	return (0);

// Affiche le nombre total de pièces nécessaires et termine le programme avec succès.

}

// Ce programme calcule le nombre minimum de pièces nécessaires pour faire la monnaie d'un montant donné, en utilisant des pièces de 25, 10, 5, 2 et 1 cent.
