#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_dog - prints a struct dog
 * @d: struct dog to print
 */
void print_dog(struct dog *d)

// C'est la déclaration de la fonction print_dog. Elle prend un seul paramètre d, qui est un pointeur vers une structure dog.

{
	if (d == NULL)
		return;

// Cette condition vérifie si le pointeur d est NULL. Si c'est le cas, la fonction se termine immédiatement sans rien faire.

	if (d->name == NULL)
		d->name = "(nil)";

// Cette condition vérifie si le champ name de la structure est NULL. Si c'est le cas, il est remplacé par la chaîne "(nil)".

	if (d->owner == NULL)
		d->owner = "(nil)";

// De même, cette condition vérifie si le champ owner de la structure est NULL. Si c'est le cas, il est remplacé par la chaîne "(nil)".

	printf("Name: %s\nAge: %f\nOwner: %s\n", d->name, d->age, d->owner);

// Cette ligne utilise printf pour afficher les informations de la structure dog. Elle imprime le nom, l'âge et le propriétaire du chien sur des lignes séparées.

}

// En résumé, cette fonction prend un pointeur vers une structure dog, vérifie si les champs name et owner sont NULL (les remplaçant par "(nil)" si c'est le cas), puis imprime toutes les informations de la structure. Si le pointeur lui-même est NULL, la fonction ne fait rien.
