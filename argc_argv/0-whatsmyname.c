#include "main.h"
#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc __attribute__((unused)), char *argv[])

// C'est la déclaration de la fonction principale main. Elle prend deux paramètres :
// argc : le nombre d'arguments passés au programme (non utilisé ici, d'où l'attribut __attribute__((unused)))
// argv : un tableau de chaînes de caractères contenant les arguments du programmeC'est la déclaration de la fonction principale main. Elle prend deux paramètres :
// argc : le nombre d'arguments passés au programme (non utilisé ici, d'où l'attribut __attribute__((unused)))
// argv : un tableau de chaînes de caractères contenant les arguments du programme

{
	printf("%s\n", *argv);

// Cette ligne imprime le premier élément du tableau argv (qui est le nom du programme) suivi d'un retour à la ligne. *argv est équivalent à argv.

	return (0);

// Cette ligne termine la fonction main en retournant 0, indiquant que le programme s'est exécuté avec succès.

}

// En résumé, ce programme imprime simplement le nom de l'exécutable (le nom du programme) et se termine. L'argument argc n'est pas utilisé dans ce code.
