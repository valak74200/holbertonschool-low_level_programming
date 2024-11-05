#include "main.h"
#include <stdio.h>

/**
 * *_memset - fills memory with a constant byte
 * @s: memory area to be filled
 * @b: char to copy
 * @n: number of times to copy b
 */
char *_memset(char *s, char b, unsigned int n)
{

// Cette ligne déclare la fonction _memset qui prend trois paramètres :
// s : un pointeur vers la zone mémoire à remplir
// b : le caractère à copier dans la mémoire
// n : le nombre de fois que b doit être copié
// La fonction retourne un pointeur de type char*.
	
	unsigned int i;

// Déclare une variable non signée i qui sera utilisée comme compteur dans la boucle.

	for (i = 0; i < n; i++)
	{

// Commence une boucle for qui s'exécutera n fois.

		s[i] = b;

// À chaque itération de la boucle, cette ligne assigne le caractère b à la position i dans la zone mémoire pointée par s.

	}

	return (s);

// Après avoir rempli la mémoire, la fonction retourne le pointeur s vers la zone mémoire modifiée.

}

// Cette fonction est utile pour initialiser ou réinitialiser une zone de mémoire avec une valeur spécifique. Par exemple, elle peut être utilisée pour effacer un buffer en le remplissant de zéros, ou pour initialiser un tableau avec une valeur par défaut.
