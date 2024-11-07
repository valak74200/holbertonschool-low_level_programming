#include "main.h"
#include <stdio.h>

/**
 * main - print the number of arguments passed to the program
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[] __attribute__((unused)))

// C'est la déclaration de la fonction principale main. Elle prend deux paramètres :
// argc : le nombre d'arguments passés au programme
// argv : un tableau de chaînes de caractères contenant les arguments du programme (non utilisé ici, d'où l'attribut __attribute__((unused)))

{
	printf("%d\n", argc - 1);

// Cette ligne imprime le nombre d'arguments passés au programme, moins 1. On soustrait 1 car le premier argument (argv) est toujours le nom du programme lui-même. Donc argc - 1 donne le nombre d'arguments supplémentaires fournis par l'utilisateur.

	return (0);

// Cette ligne termine la fonction main en retournant 0, indiquant que le programme s'est exécuté avec succès.

}

// En résumé, ce programme imprime le nombre d'arguments passés au programme (sans compter le nom du programme lui-même) et se termine. Contrairement au code précédent, ici c'est argv qui n'est pas utilisé, tandis que argc est utilisé pour calculer et afficher le nombre d'arguments.
