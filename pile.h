#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

struct pile
{
  int taille_pile ;
  int nb_elements ; // nb el dans la pile
  int iterateur ;
  void ** el ;
} ;

typedef struct pile pile_t;
pile_t * pile_creer (int nb_places) ; // Retourne NULL en cas d'erreur
void pile_detruire(pile_t * p);
void pile_initialiser(pile_t * p);
int pile_places_occupees(const pile_t * p);
int pile_places_libres(const pile_t * p);
void * pile_depiler(pile_t * p) ; // Retourne NULL si la pile est libre
int pile_depiler2(pile_t * p, void ** el); // Retourne -1 si la pile est vide, 0 sinon
int pile_empiler(pile_t * p, const void * el); // Retourne -1 si la pile est vide, 0 sinon
void pile_initialiser_iterateur(pile_t * p);
int pile_obtenir_element_suivant(pile_t * p, void ** el); // Retourne -1 si il n'y a plus d'element dans la pile, 0 sinon
