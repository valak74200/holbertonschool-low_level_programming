#include "main.h"
#include <stdio.h>

/**
 * *_strchr - locates a character in a string
 * @s: string to search
 * @c: char to find
 *
 * Return: a pointer to the first occurrence of the character
 * c in the string s, or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{

//Cette ligne déclare la fonction _strchr qui prend deux paramètres :
//s : un pointeur vers la chaîne de caractères à rechercher
//c : le caractère à trouver
//La fonction retourne un pointeur de type char*.

	int a;

//Déclare une variable entière a qui sera utilisée pour stocker chaque caractère de la chaîne

	while (1)
	{

//Commence une boucle infinie. Le code continuera à s'exécuter jusqu'à ce qu'il rencontre une instruction return.

		a = *s++;

//Cette ligne fait deux choses :
//Elle assigne à a la valeur du caractère pointé par s.
//Elle incrémente le pointeur s pour qu'il pointe vers le caractère suivant.

		if (a == c)
		{
			return (s - 1);
		}

//Si le caractère actuel (a) correspond au caractère recherché (c), la fonction retourne un pointeur vers ce caractère. s - 1 est utilisé car s a été incrémenté à la ligne précédente.

		if (a == 0)
		{
			return (NULL);
		}

//Si le caractère actuel est le caractère nul (fin de la chaîne), la fonction retourne NULL, indiquant que le caractère n'a pas été trouvé.
	}
}

//Cette implémentation est efficace car elle n'utilise qu'une seule boucle et s'arrête dès qu'elle trouve le caractère ou atteint la fin de la chaîne.
