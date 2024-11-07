#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{

// Déclaration de la fonction _atoi qui prend une chaîne de caractères en entrée et retourne un entier.

	int i, d, n, len, f, digit;

// Déclaration des variables locales :
// i : index pour parcourir la chaîne
// d : compteur de signes négatifs
// n : nombre résultant
// len : longueur de la chaîne
// f : drapeau pour indiquer si un nombre a été trouvé
// digit : valeur numérique d'un chiffre

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

// Initialisation de toutes les variables à 0.

	while (s[len] != '\0')
		len++;

// Calcul de la longueur de la chaîne.

	while (i < len && f == 0)
	{

// Début de la boucle principale qui parcourt la chaîne jusqu'à ce qu'un nombre soit trouvé ou que la fin de la chaîne soit atteinte.

		if (s[i] == '-')
			++d;

// Si le caractère est un '-', incrémente le compteur de signes négatifs.

		if (s[i] >= '0' && s[i] <= '9')
		{

// Vérifie si le caractère est un chiffre.

			digit = s[i] - '0';

// Convertit le caractère chiffre en sa valeur numérique.

			if (d % 2)
				digit = -digit;

// Si le nombre de signes négatifs est impair, le chiffre devient négatif.

			n = n * 10 + digit;

// Ajoute le chiffre au nombre en construction.

			f = 1;

// Indique qu'un nombre a été trouvé.

			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;

// Si le prochain caractère n'est pas un chiffre, sort de la boucle.

			f = 0;
		}
		i++;
	}

// Réinitialise le drapeau et passe au caractère suivant.

	if (f == 0)
		return (0);

// Si aucun nombre n'a été trouvé, retourne 0.

			return (n);

// Retourne le nombre converti.

}

/**
 * main - adds two positive number
 * @argc: number of arguments
 * @argv: array of arguents
 *
 * Return: 0 (Success), or 1 (Success)
 */
int main(int argc, char *argv[])
{

// Déclaration de la fonction main avec les paramètres standards.

	int sum, num, i, j, k;

// Déclaration des variables locales pour la somme, le nombre converti, et les indices de boucle.

	sum = 0;

// Initialisation de la somme à 0.

	for (i = 1; i < argc; i++)
	{

// Boucle sur tous les arguments (sauf le nom du programme).

		for (j = 0; argv[i][j] != '\0'; j++)
		{

// Boucle sur chaque caractère de l'argument actuel.

			if (argv[i][j] > '9' || argv[i][j] < '0')
			{
				puts("Error");
				return (1);
			}
		}
	}

// Vérifie si chaque caractère est un chiffre. Si non, affiche "Error" et termine le programme avec un code d'erreur.

	for (k = 1; k < argc; k++)
	{

// Nouvelle boucle sur tous les arguments.

		num = atoi(argv[k]);

// Convertit l'argument en nombre entier.

		if (num >= 0)
		{
			sum += num;
		}
	}

// Si le nombre est positif ou zéro, l'ajoute à la somme.

	printf("%d\n", sum);

// Affiche la somme totale.

	return (0);

// Termine le programme avec un code de succès.

}
