#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - initializes a variable of type struct dog
 * @d: pointer to struct dog to initialize
 * @name: name to initialize
 * @age: age to initialize
 * @owner: owner to initialize
 */
void init_dog(struct dog *d, char *name, float age, char *owner)

// C'est la déclaration de la fonction init_dog. Elle prend quatre paramètres :
// d : un pointeur vers une structure dog
// name : un pointeur vers une chaîne de caractères pour le nom du chien
// age : un nombre à virgule flottante pour l'âge du chien
// owner : un pointeur vers une chaîne de caractères pour le nom du propriétaire

{
	if (d == NULL)
		d = malloc(sizeof(struct dog));

// Cette condition vérifie si le pointeur d est NULL. Si c'est le cas, elle alloue dynamiquement de la mémoire pour une nouvelle structure dog en utilisant malloc.

	d->name = name;

// Cette ligne assigne la valeur du paramètre name au champ name de la structure pointée par d.

	d->age = age;

// Cette ligne assigne la valeur du paramètre age au champ age de la structure pointée par d.

	d->owner = owner;

// Cette ligne assigne la valeur du paramètre owner au champ owner de la structure pointée par d.

}

// En résumé, cette fonction initialise une structure dog avec les valeurs fournies. Si le pointeur vers la structure est NULL, elle alloue d'abord de la mémoire pour la structure avant de l'initialiser.
