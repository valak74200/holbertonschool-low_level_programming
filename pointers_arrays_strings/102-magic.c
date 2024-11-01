#include <stdio.h>

int main(void)

//Déclaration de la fonction principale.

{
  int n;
  int a[5];
  int *p;

//Déclaration des variables :
//n : un entier
//a : un tableau de 5 entiers
//p : un pointeur vers un entier

  a[2] = 1024;

//Initialisation du troisième élément du tableau a (index 2) avec la valeur 1024.

  p = &n;

//Initialisation du pointeur p avec l'adresse de la variable n.

  /*
   * write your line of code here...
   * Remember:
   * - you are not allowed to use a
   * - you are not allowed to modify p
   * - only one statement
   * - you are not allowed to code anything else than this line of code
   */
  *(p + 5) = 98;

//C'est la ligne clé du programme. Elle effectue les opérations suivantes :
//p + 5 déplace le pointeur de 5 positions entières à partir de l'adresse de n.
//*(p + 5) déréférence cette adresse, permettant d'y écrire la valeur 98.
  
  /* ...so that this prints 98\n */
  printf("a[2] = %d\n", a[2]);

//Affiche la valeur de a.

  return (0);
}

//Bien que ce code démontre une compréhension approfondie de la gestion de la mémoire en C, il n'est pas un exemple de bonne pratique de programmation. Il est utilisé uniquement à des fins éducatives pour illustrer certains concepts avancés de la manipulation de pointeurs et de mémoire en C.
