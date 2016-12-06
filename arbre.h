#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <glibc.h>
// ---------------- ARBRE ------------------------

typedef struct arbre {
  zpixel_t * zpix[3];

} arbre_t ;

typedef struct noeud {
  zpixel_t * zpix ;
  noeud_t * noeudFils[3] ;
} noeud_t ;

arbre_t * constructArbre(image_t * img);
