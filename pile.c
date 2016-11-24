#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

// Retourne NULL en cas d'erreur
pile_t * pile_creer (int nb_places){
  struct pile * pile_t ;
  if((pile_t=(struct pile *)malloc(sizeof(struct pile))) == NULL) return NULL ;
  if((pile_t->el=(void * *)malloc(sizeof(void *)*nb_places)) == NULL){
    free(pile_t);
    return NULL;
  }
  pile_t->nb_elements=0;
  pile_t->taille_pile=nb_places;
  return pile_t ;
}

void pile_detruire(pile_t * p){
  free(p->el);
  free(p);
}

void pile_initialiser(pile_t * p){
  while (p != NULL){
    p->nb_elements=0;
  }
}

int pile_places_occupees(const pile_t * p){
  int places_occupees = p->nb_elements;
	return places_occupees;
}

int pile_places_libres(const pile_t * p){
  int places_libres = (p->taille_pile) - (p->nb_elements);
	return places_libres;
}

 // Retourne NULL si la pile est libre
void * pile_depiler(pile_t * p) {
  if(p->nb_elements>0) {
    p->nb_elements--;
    return p->el[p->nb_elements];
  }
  else{
    return NULL ;
  }

}

// Retourne -1 si la pile est vide, 0 sinon
int pile_depiler2(pile_t * p, void ** el){
  if(p->nb_elements==0) return -1 ;
  p->nb_elements -- ;
  *el = p->el[p->nb_elements] ;
  return 0;
}


// Retourne -1 si la pile est vide, 0 sinon
int pile_empiler(pile_t * p, const void * el){
  if(p->nb_elements== p->taille_pile) return -1 ;
  p->el[p->nb_elements] = (void*) el ;
  p->nb_elements++;
  return 0;
}

void pile_initialiser_iterateur(pile_t * p){
  p->iterateur=0;
}

// Retourne -1 si il n'y a plus d'element dans la pile, 0 sinon
int pile_obtenir_element_suivant(pile_t * p, void ** el){
  if(p->iterateur == p->nb_elements) return -1 ;

  *el = p->el[p->iterateur];
  p->iterateur++;
  return 0;
}
