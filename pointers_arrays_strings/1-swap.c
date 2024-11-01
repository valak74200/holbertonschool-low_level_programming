#include "main.h"

/**
 * swap_int - swaps the values of two integers
 * @a: pointer to first value
 * @b: pointer to second value
 */
void swap_int(int *a, int *b)

//C'est la déclaration de la fonction :
//Elle ne retourne rien (void)
//Le nom de la fonction est swap_int
//Elle prend deux paramètres, a et b, qui sont des pointeurs vers des entiers

{
	int c;

//Début du corps de la fonction et déclaration d'une variable entière c qui servira de variable temporaire pour l'échange.

	c = *a;

//On stocke la valeur pointée par a dans la variable temporaire c.
	*a = *b;

//On assigne la valeur pointée par b à l'adresse pointée par a.
	*b = c;

//On assigne la valeur temporaire c (qui contient l'ancienne valeur de *a) à l'adresse pointée par b.

}

//En résumé, cette fonction swap_int échange les valeurs de deux entiers en utilisant leurs adresses (pointeurs). Elle utilise une variable temporaire c pour effectuer l'échange sans perdre de données. Après l'exécution de cette fonction, la valeur initialement pointée par a se trouvera à l'adresse pointée par b, et vice versa.
