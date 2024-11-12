#include <stdlib.h>
#include "main.h"

/**
 * *malloc_checked - allocates memory using malloc
 * @b: number of bytes to allocate
 *
 * Return: a pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)

// C'est la déclaration de la fonction malloc_checked. Elle prend un paramètre unsigned int b (le nombre d'octets à allouer) et retourne un pointeur void * (un pointeur générique qui peut être converti en n'importe quel type de pointeur).

{
	void *ptr;

// Cette ligne déclare un pointeur void * nommé ptr qui sera utilisé pour stocker l'adresse de la mémoire allouée.

	ptr = malloc(b);

// Cette ligne appelle la fonction malloc() pour allouer b octets de mémoire et stocke l'adresse retournée dans ptr.

	if (ptr == NULL)
		exit(98);

// Cette condition vérifie si l'allocation de mémoire a échoué. Si malloc() retourne NULL (ce qui indique un échec d'allocation), la fonction termine le programme avec un code de sortie de 98. C'est une façon de gérer les erreurs d'allocation de mémoire de manière stricte.

	return (ptr);
}

// Si l'allocation réussit, la fonction retourne le pointeur vers la mémoire allouée.

// Cette fonction est une enveloppe (wrapper) autour de malloc() qui ajoute une vérification d'erreur supplémentaire. Au lieu de simplement retourner NULL en cas d'échec d'allocation (comme le fait malloc()), cette fonction termine le programme avec un code d'erreur spécifique. Cela peut être utile dans les situations où vous voulez être absolument certain que l'allocation de mémoire a réussi, et où vous préférez que le programme se termine plutôt que de continuer avec une allocation de mémoire échouée.
