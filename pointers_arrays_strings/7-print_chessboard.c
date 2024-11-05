#include "main.h"

/**
 * print_chessboard - prints the chessboard
 * @a: two dimension array to print
 */
void print_chessboard(char (*a)[8])
{

//Cette ligne déclare la fonction print_chessboard qui prend un paramètre :
//a : un pointeur vers un tableau de 8 caractères, ce qui équivaut à un tableau 2D de 8x8 caractères.
//La fonction ne retourne rien (void).

	int i, j;

//Déclare deux variables entières utilisées comme compteurs dans les boucles.

	for (i = 0; i < 8; i++)
	{

//Commence une boucle externe qui itère 8 fois, représentant les 8 rangées de l'échiquier.

		for (j = 0; j < 8; j++)
		{
			_putchar(a[i][j]);
		}

//Pour chaque rangée, cette boucle interne itère 8 fois, représentant les 8 colonnes de l'échiquier. Elle utilise _putchar pour imprimer chaque caractère du tableau.

		_putchar('\n');
	}
}

//Après avoir imprimé une rangée complète, la fonction ajoute un saut de ligne avec _putchar('\n'), puis passe à la rangée suivante.
