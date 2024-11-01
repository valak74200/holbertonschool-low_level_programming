#include "main.h"
#include <stdio.h>

/**
 * *_strncat - concatenates two strings
 * @src: string to add
 * @dest: string to append do
 * @n: number of bytes of str to concatenate
 *
 * Return: a pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)

//Déclaration de la fonction. Elle prend trois paramètres : deux chaînes de caractères (dest et src) et un entier n. Elle retourne un pointeur vers une chaîne de caractères.//

{
	int dest_len = 0;
	int i;
	
//Déclaration des variables locales : dest_len pour stocker la longueur de dest, et i comme compteur.//

	while (dest[dest_len] != '\0')
		dest_len++;
	
//Cette boucle calcule la longueur de la chaîne dest en comptant les caractères jusqu'au caractère nul '\0'.//

	for (i = 0; i < n && src[i] != '\0'; i++)  
		dest[dest_len + i] = src[i];
	
//Cette boucle copie au maximum n caractères de src à la fin de dest. Elle s'arrête si elle atteint n caractères ou la fin de src.//

			if (i < n)
				dest[dest_len + i] = '\0';
			
//Si la boucle s'est arrêtée avant d'atteindre n (c'est-à-dire, si src était plus courte que n), on ajoute un caractère nul à la fin de la chaîne résultante.//

	return (dest);

//La fonction retourne un pointeur vers la chaîne dest modifiée//

}

//En résumé, cette fonction _strncat concatène jusqu'à n caractères de la chaîne src à la fin de la chaîne dest, en s'assurant que le résultat est correctement terminé par un caractère nul. Elle retourne ensuite un pointeur vers dest.//
