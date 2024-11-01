#include "main.h"

/**
 * _puts - prints a string to stdout
 * @str: pointer to the string to print
 */
void _puts(char *str)

//C'est la déclaration de la fonction :
//Elle ne retourne rien (void)
//Le nom de la fonction est _puts
//Elle prend un paramètre str qui est un pointeur vers un char (une chaîne de caractères)

{
	int i;

//Début du corps de la fonction et déclaration d'une variable entière i qui servira de compteur.

	for (i = 0; str[i] != '\0'; i++)
	{

//Début d'une boucle for. Elle continue tant que le caractère à la position i dans la chaîne str n'est pas le caractère nul '\0' (qui marque la fin d'une chaîne en C).

		_putchar(str[i]);

//À chaque itération de la boucle, cette ligne appelle la fonction _putchar pour imprimer le caractère actuel de la chaîne.

	}
	_putchar('\n');

//Après avoir imprimé tous les caractères de la chaîne, cette ligne imprime un caractère de nouvelle ligne.

}

//En résumé, cette fonction _puts imprime une chaîne de caractères sur la sortie standard, un caractère à la fois, en utilisant la fonction _putchar. Après avoir imprimé toute la chaîne, elle ajoute un saut de ligne. C'est une implémentation personnalisée de la fonction standard puts de la bibliothèque stdio.h.//
