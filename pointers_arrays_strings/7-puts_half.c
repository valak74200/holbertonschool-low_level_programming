#include "main.h"

/**
 * puts_half - print the second half of the string
 * @str: string to be printed
 */
void puts_half(char *str)

//Déclaration de la fonction puts_half qui prend un pointeur vers une chaîne de caractères et ne retourne rien (void).

{
	int len, n, i;

//Déclaration des variables :
//len pour stocker la longueur de la chaîne
//n et i utilisés comme compteurs dans les boucles

	len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

//Calcul de la longueur de la chaîne en comptant les caractères jusqu'au caractère nul ('\0').

	if (len % 2 == 0)
	{
		for (i = len / 2; str[i] != '\0'; i++)
		{
			_putchar(str[i]);
		}

//Si la longueur de la chaîne est paire :
//Commence à imprimer à partir du milieu exact de la chaîne (len / 2)
//Imprime jusqu'à la fin de la chaîne

	} else if (len % 2)
	{
		for (n = (len - 1) / 2; n < len - 1; n++)
		{
			_putchar(str[n + 1]);
		}
	}

//Si la longueur de la chaîne est impaire :
//Calcule le point de départ comme (len - 1) / 2
//Imprime à partir du caractère suivant ce point jusqu'à l'avant-dernier caractère de la chaîne

	_putchar('\n');

//Imprime un caractère de nouvelle ligne à la fin.

}

//En résumé, puts_half est une fonction bien conçue pour imprimer la seconde moitié d'une chaîne, avec une gestion appropriée des cas pairs et impairs. Elle est efficace et directe, bien qu'elle puisse bénéficier de quelques améliorations mineures pour la rendre plus robuste.
