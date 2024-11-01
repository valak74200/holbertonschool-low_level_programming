#include "main.h"
#include <stdio.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 * Return: the int converted from the string
 */
int _atoi(char *s)

//Déclaration de la fonction _atoi qui prend un pointeur vers une chaîne de caractères et retourne un entier.

{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

//Déclaration et initialisation des variables :
//i : index pour parcourir la chaîne
//d : compteur de signes négatifs
//n : résultat final
//len : longueur de la chaîne
//f : drapeau pour indiquer si un nombre a été trouvé
//digit : valeur numérique du caractère actuel

	while (s[len] != '\0')
		len++;

//Calcul de la longueur de la chaîne.

	while (i < len && f == 0)
	{

//Boucle principale qui parcourt la chaîne jusqu'à ce qu'un nombre soit complètement lu ou que la fin de la chaîne soit atteinte.

		if (s[i] == '-')
			++d;

//Compte le nombre de signes négatifs rencontrés.

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;

		}

//Cette partie traite les chiffres :
//Convertit le caractère en valeur numérique
//Applique le signe négatif si nécessaire
//Ajoute le chiffre au résultat
//Vérifie si c'est le dernier chiffre de la séquence

		i++;
	}

	if (f == 0)
		return (0);

			return (n);

//Retourne 0 si aucun nombre n'a été trouvé, sinon retourne le nombre converti.

}

//En résumé, cette fonction _atoi est une implémentation robuste pour convertir une chaîne en entier, avec une bonne gestion des cas particuliers comme les signes négatifs et les caractères non numériques. Cependant, elle pourrait être améliorée en termes de gestion des erreurs et de conformité exacte avec le comportement de atoi standard.
