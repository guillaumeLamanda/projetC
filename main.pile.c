#include <limits.h>
#include <stdio.h>
#include <stdarg.h>

#include "pile.h"

int main(void) {
	// A faire : Tester retour des fonctions

	printf("Declaration de la pile ... ");
	pile_t* premiere_pile; //declaration de la pile
	printf("OK\n");

	printf("Creation de la pile ... ");
	premiere_pile = pile_creer(10); //creation de la pile avec 10 places
	if(premiere_pile != NULL){
		printf("OK\n\n");
	}
	else{
		printf("Erreur\n" );
	}

	printf(" - Places occupees : %d\n", pile_places_occupees(premiere_pile));
	printf(" - Places libres : %d\n", pile_places_libres(premiere_pile));

  printf("\n");

  int valeur1 = 5 ;
  printf(" -- On empile\n");
	int retour ;
  retour = pile_empiler(premiere_pile, &valeur1);
	if(retour == -1){
		printf("La pile est vide\n");
	}
  int valeur2 = 65;
  retour = pile_empiler(premiere_pile, &valeur2);
	if(retour == -1){
		printf("La pile est vide\n");
	}

	printf(" - Places occupees : %d\n", pile_places_occupees(premiere_pile));
	printf(" - Places libres : %d\n", pile_places_libres(premiere_pile));

  void * el = NULL ;
  printf("Definition nouvel el OK\n");
  pile_initialiser_iterateur(premiere_pile);
  printf("Definition iterateur OK\n");

  printf("\n On parcours la pile\n");
  while(pile_obtenir_element_suivant(premiere_pile, &el) == 0){
    printf("El : %d\n", *(int*)el);
  }

  printf("\n -- On dépile avec depile \n");
  el = pile_depiler(premiere_pile);
	if(el == NULL){
		printf("La pile est libre\n");
	}

	printf(" - Places occupees : %d\n", pile_places_occupees(premiere_pile));
	printf(" - Places libres : %d\n", pile_places_libres(premiere_pile));

	printf("\n -- On dépile avec depile2 \n");
  retour = pile_depiler2(premiere_pile, el);
	if(retour == -1){
		printf("La pile est vide\n");
	}

	printf(" - Places occupees : %d\n", pile_places_occupees(premiere_pile));
	printf(" - Places libres : %d\n", pile_places_libres(premiere_pile));

	printf("\n -- On dépile avec depile2 \n");
  retour = pile_depiler2(premiere_pile, el);
	if(retour == -1){
		printf("La pile est vide\n");
	}

  printf("\nLa pile possède %d places libres et %d places occupees\n", pile_places_libres(premiere_pile), pile_places_occupees(premiere_pile));

	printf("\nSuppression de la pile ... ");
	pile_detruire(premiere_pile); //detruire la pile
	printf("OK\n");

	return 0;
}
