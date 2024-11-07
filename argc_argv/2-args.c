#include "main.h"
#include <stdio.h>

/**
 * main - print all arguments it receives
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])

// C'est la déclaration de la fonction principamain. Elle prend deux paramètres :
// argc : le nombre d'arguments passés au programme
// argv : un tableau de chaînes de caractères contenant les arguments du programme

{
	int i;

// Déclare une variable entière i qui sera utilisée comme compteur dans la boucle for.

	for (i = 0; i < argc; i++)

// C'est une boucle for qui va itérer de 0 à argc - 1. Elle va parcourir tous les éléments du tableau argv.

	{
		printf("%s\n", argv[i]);

// Cette ligne imprime chaque argument stocké dans argv[i], suivi d'un retour à la ligne. Cela se répète pour chaque argument.

	}

	return (0);

// Cette ligne termine la fonction main en retournant 0, indiquant que le programme s'est exécuté avec succès.

}

// En résumé, ce programme imprime tous les arguments passés au programme, y compris le nom du programme lui-même (qui est toujours le premier argument, argv). Chaque argument est imprimé sur une nouvelle ligne. Ce code utilise à la fois argc et argv pour accomplir sa tâche.
