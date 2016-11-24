#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

typedef struct zpixel
{
  int size ;
  struct{
    int x; int y;
  } position;
  struct {
    int r;
    int g;
    int b;
  } rgb;
  double degradFact ; // Facteur de dégradation
} zpixel_t;

zpixel_t * zpixel_creer(int x, int y, int size);

void zpixel_initialiser(zpixel_t *zp, int r, int g, int b);

double luminosite(zpixel_t *zp);

int min(zpixel_t *zp);

int max(zpixel_t *zp);

double distance(zpixel_t * zp1, zpixel_t * zp2);

// Structure image
typedef struct image
{
  int nblignes ;
  int nbcols ;
  // Si nblignes * nbcols n'est pas un multiple de 4,
  // rowtrip est ajouté pour y parvenir
  int rowstrip ;
} image_t ;