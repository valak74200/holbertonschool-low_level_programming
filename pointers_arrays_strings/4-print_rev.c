#include "main.h"

/**
 * print_rev - prints a string, in reverse
 * @s: string to be printed
 */
void print_rev(char *s)

//C'est la déclaration de la fonction :
//Elle ne retourne rien (void)
//Le nom de la fonction est print_rev
//Elle prend un paramètre s qui est un pointeur vers un char (une chaîne de caractères)

{
	int i, j, len;

//Début du corps de la fonction et déclaration de trois variables entières : i et j serviront de compteurs, et len stockera la longueur de la chaîne.

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

//Cette boucle while calcule la longueur de la chaîne en comptant les caractères jusqu'au caractère nul '\0'.

	len = i;

//On stocke la longueur de la chaîne dans la variable len.

	for (j = len - 1; j >= 0; j--)
	{
		_putchar(s[j]);
	}

//Cette boucle for parcourt la chaîne de la fin vers le début (j commence à len - 1 et décrémente jusqu'à 0). À chaque itération, elle imprime le caractère actuel avec _putchar.
	
	_putchar('\n');

//Après avoir imprimé tous les caractères de la chaîne à l'envers, cette ligne imprime un caractère de nouvelle ligne.
}

//En résumé, cette fonction print_rev imprime une chaîne de caractères à l'envers. Elle commence par calculer la longueur de la chaîne, puis utilise cette information pour parcourir la chaîne de la fin vers le début, imprimant chaque caractère avec _putchar. Enfin, elle ajoute un saut de ligne.
