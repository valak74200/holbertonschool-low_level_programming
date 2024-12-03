#ifndef CALC_H
#define CALC_H

// Ces lignes sont des directives de préprocesseur qui empêchent l'inclusion multiple de ce fichier d'en-tête. Si CALC_H n'est pas défini, le contenu entre #ifndef et #endif sera inclus, et CALC_H sera défini.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ces lignes incluent les bibliothèques standard nécessaires pour les opérations d'entrée/sortie (stdio.h), l'allocation de mémoire et la conversion de chaînes (stdlib.h), et la manipulation de chaînes (string.h).

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;

// Cette partie définit une structure nommée op et crée un alias op_t pour cette structure. La structure contient :
// char *op : un pointeur vers une chaîne de caractères (probablement pour stocker l'opérateur)
// int (*f)(int a, int b) : un pointeur vers une fonction qui prend deux entiers comme arguments et retourne un entier

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

// Ces lignes déclarent cinq fonctions pour les opérations arithmétiques de base : addition, soustraction, multiplication, division et modulo.

int (*get_op_func(char *s))(int, int);

// Cette ligne déclare une fonction get_op_func qui prend une chaîne de caractères comme argument et retourne un pointeur vers une fonction qui prend deux entiers comme arguments et retourne un entier. Cette fonction sera probablement utilisée pour sélectionner l'opération arithmétique appropriée en fonction de l'opérateur fourni.

#endif

// Cette directive de préprocesseur marque la fin du bloc #ifndef, fermant ainsi la protection contre l'inclusion multiple.

// En résumé, ce fichier d'en-tête définit une structure pour associer des opérateurs à des fonctions, déclare des fonctions pour les opérations arithmétiques de base, et une fonction pour sélectionner l'opération appropriée. Il est conçu pour être utilisé dans un programme de calculatrice simple.
