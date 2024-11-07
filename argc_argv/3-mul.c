#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers
 * @argc: number of arguments
 * @argv: array containing arguments
 *
 * Return: 0 if Success, 1 if error
 */
int main(int argc, char *argv[])

// Déclaration de la fonction principale main avec ses paramètres argc et argv.

{
	int num1, num2, result;

// Déclaration des variables entières pour stocker les deux nombres à multiplier et leur résultat.

	if (argc != 3)

// Vérifie si le nombre d'arguments est différent de 3 (le nom du programme + 2 nombres).

	{
		printf("Error\n");
		return (1);
	}

// Si le nombre d'arguments est incorrect, affiche "Error" et retourne 1 (indiquant une erreur).

	num1 = atoi(argv[1]);

// Convertit le premier argument (après le nom du programme) en entier.

	num2 = atoi(argv[2]);

// Convertit le deuxième argument en entier.

	result = num1 * num2;

// Multiplie les deux nombres et stocke le résultat.

	printf("%d\n", result);

// Affiche le résultat de la multiplication.

	return (0);

// Retourne 0, indiquant que le programme s'est exécuté avec succès.

}

// En résumé, ce programme :
// Vérifie s'il a reçu exactement deux arguments (en plus du nom du programme).
// Si ce n'est pas le cas, il affiche "Error" et se termine avec un code d'erreur.
// Si c'est le cas, il convertit ces deux arguments en nombres entiers.
// Il multiplie ces deux nombres.
// Il affiche le résultat de la multiplication.
// Il se termine en indiquant un succès.
