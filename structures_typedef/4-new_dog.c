#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

// Cette fonction _strlen calcule la longueur d'une chaîne de caractères. Elle parcourt la chaîne jusqu'à trouver le caractère nul de fin et retourne le nombre de caractères comptés.

/**
 * _strcpy - copies the string pointed to by src to dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// La fonction _strcpy copie une chaîne source (src) dans une chaîne de destination (dest). Elle copie chaque caractère jusqu'au caractère nul de fin, puis ajoute le caractère nul à la fin de dest.

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 * Return: pointer to the new dog (Success), NULL otherwise
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	int len1, len2;

// La fonction new_dog commence ici. Elle déclare un pointeur dog et deux variables pour stocker les longueurs des chaînes name et owner.

	len1 = _strlen(name);
	len2 = _strlen(owner);

// Ces lignes calculent les longueurs des chaînes name et owner.

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

// Ici, on alloue de la mémoire pour la structure dog_t. Si l'allocation échoue, la fonction retourne NULL.

	dog->name = malloc(sizeof(char) * (len1 + 1));
	if (dog->name == NULL)
	{
		free(dog->name);
		return (NULL);
	}

// On alloue de la mémoire pour le nom du chien. Si l'allocation échoue, on libère la mémoire et on retourne NULL.

	dog->owner = malloc(sizeof(char) * (len2 + 1));
	if (dog->owner == NULL)
	{
		free(dog->owner);
		return (NULL);
	}

// De même, on alloue de la mémoire pour le nom du propriétaire et on gère les erreurs.

	_strcpy(dog->name, name);
	_strcpy(dog->owner, owner);
	dog->age = age;

// On copie les chaînes name et owner dans les champs correspondants de la structure dog et on assigne l'âge.

	return (dog);

// Enfin, on retourne le pointeur vers la nouvelle structure dog_t.

}

// En résumé, ce code définit des fonctions utilitaires pour manipuler des chaînes de caractères et une fonction principale new_dog qui crée une nouvelle structure dog_t, alloue de la mémoire pour ses champs, les initialise avec les valeurs fournies, et retourne un pointeur vers cette nouvelle structure.
