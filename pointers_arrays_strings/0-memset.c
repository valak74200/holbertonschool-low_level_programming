#include "main.h"
#include <stdio.h>

/**
 * *_memset - fills memory with a constant byte
 * @s: memory area to be filled
 * @b: char to copy
 * @n: number of times to copy b
 */
char *_memset(char *s, char b, unsigned int n)

// C'est la déclaration de la fonction _memset. Elle prend trois paramètres :
// s : un pointeur vers la zone mémoire à remplir
// b : le caractère à copier dans la mémoire
// n : le nombre de fois que b doit être copié

{
	unsigned int i;

// Déclaration de la variable i de type unsigned int qui sera utilisée comme compteur dans la boucle.

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

// Cette boucle for itère n fois. À chaque itération, elle copie le caractère b dans la position i de la zone mémoire pointée par s.

	return (s);

// La fonction retourne le pointeur s, qui pointe maintenant vers la zone mémoire modifiée.

}

// En résumé, cette fonction est une implémentation personnalisée de la fonction standard memset. Elle remplit les n premiers octets de la zone mémoire pointée par s avec le caractère b. Cette fonction est utile pour initialiser ou réinitialiser une zone mémoire avec une valeur spécifique.
