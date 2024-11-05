#include "main.h"
#include <stdio.h>

/**
 * *_memcpy - copies memory area
 * @dest: destination memory area
 * @src: memory area to copy from
 * @n: number of bytes to copy
 *
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{

//Cette ligne déclare la fonction _memcpy qui prend trois paramètres :
//dest : un pointeur vers la zone mémoire de destination
//src : un pointeur vers la zone mémoire source
//n : le nombre d'octets à copier
//La fonction retourne un pointeur de type char*.

	unsigned int i;

//Déclare une variable non signée i qui sera utilisée comme compteur dans la boucle.

	for (i = 0; i < n; i++)
	{

//Commence une boucle for qui s'exécutera n fois.

		dest[i] = src[i];

//À chaque itération de la boucle, cette ligne copie l'octet à la position i de la source (src) vers la position i de la destination (dest).

	}

	return (dest);

//Après avoir copié la mémoire, la fonction retourne le pointeur dest vers la zone mémoire de destination.

}

//Cette fonction est utile pour copier des blocs de mémoire d'un endroit à un autre. Elle peut être utilisée pour copier des tableaux, des structures, ou tout autre bloc de données en mémoire.
//Il est important de noter que cette fonction ne vérifie pas les chevauchements entre les zones mémoire source et destination. Si les zones se chevauchent, le comportement peut être indéfini. Pour les cas où un chevauchement est possible, il faudrait utiliser une fonction comme memmove.
