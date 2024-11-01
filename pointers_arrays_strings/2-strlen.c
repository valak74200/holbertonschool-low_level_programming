#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 * Return: the length of the string
 */
int _strlen(char *s)

//C'est la déclaration de la fonction :
//Elle retourne un int (la longueur de la chaîne)
//Le nom de la fonction est _strlen
//Elle prend un paramètre s qui est un pointeur vers un char (une chaîne de caractères)

{
	int i;

//Déclaration d'une variable entière i qui sera utilisée comme compteur.//	

	i = 0;

//Initialisation de i à 0.//	

	while (s[i] != '\0')
	{

//Début d'une boucle while. Elle continue tant que le caractère à la position i dans la chaîne s n'est pas le caractère nul '\0' (qui marque la fin d'une chaîne en C).//		
		i++;

//Incrémente i à chaque itération de la boucle.//		
	
	}

	return (i);

//Retourne la valeur finale de i, qui représente le nombre de caractères dans la chaîne (sa longueur)//

}

//En résumé, cette fonction parcourt la chaîne caractère par caractère, en comptant combien il y en a jusqu'à ce qu'elle atteigne le caractère nul de fin de chaîne. Le compte final est la longueur de la chaîne, qui est alors retournée.//
