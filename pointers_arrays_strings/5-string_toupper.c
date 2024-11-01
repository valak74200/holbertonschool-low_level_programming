#include "main.h"
#include <stdio.h>

/**
 * *string_toupper - string to uppercase
 * @s: string to modify
 *
 * Return: the resulting string
 *
 */
char *string_toupper(char *s)

//Déclaration de la fonction string_toupper qui :
//Prend un pointeur vers une chaîne de caractères (char *s) comme argument.
//Retourne un pointeur vers une chaîne de caractères (char *).

{
	int i;

//Déclaration de la variable i qui sera utilisée comme compteur dans la boucle.

	for (i = 0; s[i] != '\0'; i++)

//Boucle for qui parcourt la chaîne de caractères jusqu'à ce qu'elle atteigne le caractère nul ('\0') qui marque la fin de la chaîne.

	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
	}

//À l'intérieur de la boucle :
//Vérifie si le caractère actuel est une lettre minuscule (entre 'a' et 'z').
//Si c'est le cas, soustrait 32 de sa valeur ASCII pour obtenir la majuscule correspondante.
//(La différence entre les codes ASCII des minuscules et des majuscules est de 32.)

return (s);

//Retourne le pointeur vers la chaîne modifiée.

}

//En résumé, string_toupper est une fonction efficace et concise pour convertir une chaîne en majuscules. Elle est simple à comprendre et à utiliser, bien qu'elle puisse bénéficier de quelques améliorations mineures pour la rendre plus robuste et portable.
