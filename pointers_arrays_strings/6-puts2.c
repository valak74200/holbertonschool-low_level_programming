#include "main.h"

/**
 * puts2 - prints one char out of 2 of a string
 * followed by a new line
 * @str: string to print the chars from
 */
void puts2(char *str)

//Déclaration de la fonction puts2 qui prend un pointeur vers une chaîne de caractères (char *str) et ne retourne rien (void).

{
	int len, i;

//Déclaration de deux variables entières :
//len pour stocker la longueur de la chaîne
//i pour être utilisé comme compteur dans la boucle d'impression

	len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

//Cette boucle calcule la longueur de la chaîne en comptant les caractères jusqu'au caractère nul ('\0').

	for (i = 0; i < len; i += 2)
	{
		_putchar(str[i]);
	}

//Cette boucle parcourt la chaîne et imprime un caractère sur deux :
//Elle commence à l'index 0 et incrémente i de 2 à chaque itération.
//_putchar(str[i]) imprime le caractère à l'index i.

	_putchar('\n');

//Imprime un caractère de nouvelle ligne à la fin.

}

//En résumé, puts2 est une fonction simple et efficace pour imprimer un caractère sur deux d'une chaîne. Elle est facile à comprendre et à utiliser, bien qu'elle puisse bénéficier de quelques améliorations mineures pour la rendre plus robuste.
