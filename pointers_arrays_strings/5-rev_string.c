#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string to be reversed
 */
void rev_string(char *s)

//Déclaration de la fonction rev_string qui prend un pointeur vers une chaîne de caractères (char *s) et ne retourne rien (void).

{
	char tmp;
	int i, len, len1;

//Déclaration des variables locales :
//tmp : variable temporaire pour l'échange de caractères
//i : compteur pour la boucle d'inversion
//len : longueur totale de la chaîne
//len1 : index du dernier caractère de la chaîne

	len = 0;
	len1 = 0;

	while (s[len] != '\0')
	{
		len++;
	}

//Calcul de la longueur de la chaîne en comptant les caractères jusqu'au caractère nul ('\0').

	len1 = len - 1;

//Initialisation de len1 à l'index du dernier caractère de la chaîne (longueur - 1).

	for (i = 0; i < len / 2; i++)
	{
		tmp = s[i];
		s[i] = s[len1];
		s[len1--] = tmp;
	}

//Boucle principale qui inverse la chaîne :
//Elle s'exécute jusqu'à la moitié de la chaîne (len / 2).
//À chaque itération :
//tmp stocke temporairement le caractère à l'index i
//Le caractère à l'index i est remplacé par celui à l'index len1
//Le caractère à l'index len1 est remplacé par tmp
//len1 est décrémenté après l'affectation (len1--)

}

//En résumé, cette fonction rev_string est une implémentation efficace et concise pour inverser une chaîne de caractères en place. Elle utilise une technique d'échange symétrique des caractères, ce qui la rend à la fois simple à comprendre et efficace en termes de performance.
