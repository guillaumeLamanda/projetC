#include <limits.h>
#include <stdio.h>
#include <stdarg.h>

#include "pile.h"

int main(void) {

	printf("Declaration de la pile ... ");
	pile_t* premiere_pile; //declaration de la pile
	printf("OK\n");

	printf("Creation de la pile ... ");
	premiere_pile = pile_creer(10); //creation de la pile avec 10 places
	printf("OK\n\n");


	pile_places_occupees(premiere_pile);
	pile_places_libres(premiere_pile);

  printf("\n");

  int valeur = 5 ;
  printf(" -- On empile\n");
  pile_empiler(premiere_pile, &valeur);
  valeur = 65;
  pile_empiler(premiere_pile, &valeur);

  pile_places_occupees(premiere_pile);
	pile_places_libres(premiere_pile);

  void * el = NULL ;
  printf("Definition nouvel el OK\n");
  pile_initialiser_iterateur(premiere_pile);
  printf("Definition iterateur OK\n");

  printf("\n On parcours la pile\n");
  while(pile_obtenir_element_suivant(premiere_pile, &el) == 0){
    printf("El : %p\n", &el);
  }

  printf("\n -- On dépile \n");
  pile_depiler(premiere_pile);

  pile_places_occupees(premiere_pile);
	pile_places_libres(premiere_pile);

  printf("\nLa pile possède %d places libres et %d places occupees\n", pile_places_libres(premiere_pile), pile_places_occupees(premiere_pile));

	printf("\nSuppression de la pile ... ");
	pile_detruire(premiere_pile); //detruire la pile
	printf("OK\n");

	return 0;
}
