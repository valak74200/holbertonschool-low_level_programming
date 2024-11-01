#include <stdio.h>
#include "main.h"

/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)

//Déclaration de la fonction _strcpy qui prend deux paramètres :
//dest : pointeur vers la chaîne de destination
//src : pointeur vers la chaîne source
//La fonction retourne un pointeur vers la chaîne de destination.

{
	int len, i;

//Déclaration de deux variables entières :
//len pour stocker la longueur de la chaîne source
//i utilisé comme compteur dans la boucle de copie

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

//Calcul de la longueur de la chaîne source en comptant les caractères jusqu'au caractère nul ('\0').

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}

//Boucle qui copie chaque caractère de src vers dest.

	dest[i] = '\0';

//Ajout du caractère nul à la fin de la chaîne de destination.

	return (dest);

//Retourne le pointeur vers la chaîne de destination.

}

//En résumé, _strcpy est une implémentation fonctionnelle et compréhensible de la fonction de copie de chaîne. Elle remplit son rôle principal correctement, mais pourrait bénéficier de quelques améliorations en termes de sécurité et d'efficacité pour être utilisée dans un environnement de production.
