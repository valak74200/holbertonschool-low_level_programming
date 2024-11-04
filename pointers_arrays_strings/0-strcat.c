#include "main.h"
#include <stdio.h>

/**
 * *_strcat - contains two strings
 * @dest: string to append to
 * @src: string to add
 *
 * Return: string to add
 */
char *_strcat(char *dest, char *src)

//Déclaration de la fonction _strcat qui prend deux pointeurs vers des chaînes de caractères (char *dest et char *src) et retourne un pointeur vers char.
{

	int i, j;

//Déclaration de deux variables entières i et j, utilisées comme index pour parcourir dest et src.

	i = 0;
	j = 0;

//Initialisation des variables i et j à 0.

	while (dest[i] != '\0')
		i++;

//Boucle while qui incrémente i jusqu'à atteindre le caractère nul ('\0') à la fin de la chaîne dest. Cela place i à l'indice où commence l'ajout de src.

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;

//Cette boucle copie les caractères de src à la fin de dest. Elle s'arrête lorsqu'elle atteint la fin de src.

	}

	dest[i] = '\0';

//Ajoute le caractère nul à la fin de la chaîne concaténée dans dest.

	return (dest);

//Retourne le pointeur vers la chaîne de destination modifiée.

}

//En résumé, cette fonction implémente efficacement la concaténation de chaînes, mais devrait être utilisée avec précaution en s'assurant que le buffer de destination est suffisamment grand pour éviter les débordements.
