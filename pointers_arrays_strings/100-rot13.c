#include "main.h"
#include <stdio.h>

/**
 * *rot13 - rotate by 13 places
 * @s: string to be encoded
 *
 * Return: the resulting string
 */
char *rot13(char *s)

//Déclaration de la fonction rot13 qui prend un pointeur vers une chaîne de caractères et retourne un pointeur vers une chaîne de caractères.

{
	int i, j;

	i = 0;
	j = 0;

//Déclaration et initialisation des variables de compteur i et j.

	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char b[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

//Définition de deux tableaux de caractères :
//a contient l'alphabet en ordre normal (majuscules puis minuscules).
//b contient l'alphabet décalé de 13 positions (le résultat ROT13 de a).

	for (i = 0; s[i] != '\0'; i++)
	{

		for (j = 0; a[j] != '\0'; j++)
		{
			if (s[i] == a[j])
			{
				s[i] = b[j];
				break;
			}
		}
	}

//Boucles imbriquées :
//La boucle externe parcourt chaque caractère de la chaîne d'entrée s.
//La boucle interne cherche le caractère correspondant dans a.
//Si une correspondance est trouvée, le caractère dans s est remplacé par le caractère correspondant dans b.
//Le break permet de sortir de la boucle interne dès qu'une correspondance est trouvée.

	return (s);

//Retourne la chaîne modifiée.

}

//En résumé, cette fonction implémente efficacement le chiffrement ROT13 en utilisant des boucles imbriquées pour effectuer des substitutions basées sur des tableaux préconfigurés.
