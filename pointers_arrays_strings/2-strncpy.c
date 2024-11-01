#include <stdio.h>
#include "main.h"

/**
 * *_strncpy - string copy
 * @dest: destination
 * @src: source
 * @n: number of bytes to copy
 *
 * Return: pointer to the result
 */
char *_strncpy(char *dest, char *src, int n)

//Déclaration de la fonction _strncpy. Elle prend trois paramètres : deux chaînes de caractères (dest et src) et un entier n. Elle retourne un pointeur vers une chaîne de caractères.//

{
	int i;

//Début du corps de la fonction et déclaration d'une variable entière i qui servira de compteur.//

	i = 0;

//Initialisation de i à 0.//

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}

//Cette boucle copie les caractères de src vers dest jusqu'à ce qu'elle atteigne la fin de src ('\0') ou qu'elle ait copié n caractères.//

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

//Si la première boucle s'est terminée avant d'avoir copié n caractères (c'est-à-dire si src était plus courte que n), cette boucle remplit le reste de dest avec des caractères nuls.//

	return (dest);

//La fonction retourne un pointeur vers la chaîne dest modifiée.//

}

//En résumé, cette fonction _strncpy copie jusqu'à n caractères de la chaîne src vers la chaîne dest. Si src contient moins de n caractères, dest est complété avec des caractères nuls jusqu'à ce que n caractères au total aient été écrits. Cette fonction est similaire à la fonction standard strncpy de la bibliothèque string.h, mais avec une implémentation personnalisée.En résumé, cette fonction _strncpy copie jusqu'à n caractères de la chaîne src vers la chaîne dest. Si src contient moins de n caractères, dest est complété avec des caractères nuls jusqu'à ce que n caractères au total aient été écrits. Cette fonction est similaire à la fonction standard strncpy de la bibliothèque string.h, mais avec une implémentation personnalisée.//
//
