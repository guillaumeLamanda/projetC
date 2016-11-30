#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

// ----------------- ZPIXEL -----------------------
typedef struct zpixel
{
  int size ;
  struct{
    int x; int y;
  } position;
  struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
  } rgb;
  double degradFact ; // Facteur de dégradation
} zpixel_t;

// ----------------- PIXEL -----------------------
typedef struct pixel {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} pixel_t ;

// ----------------- IMAGE -----------------------
typedef struct image
{
  int nblignes ;
  int nbcols ;
  // Si nblignes * nbcols n'est pas un multiple de 4,
  // rowtrip est ajouté pour y parvenir
  int rowstride ;

  pixel_t* pixels ;
} image_t ;


// ----------------- ZPIXEL -----------------------
zpixel_t * zpixel_creer(int x, int y, int size);

void zpixel_initialiser(zpixel_t *zp, int r, int g, int b);

double luminosite(zpixel_t *zp);

int min(zpixel_t *zp);

int max(zpixel_t *zp);

double distance(zpixel_t * zp1, zpixel_t * zp2);

double saturation(zpixel_t *zp);

void projection(zpixel_t * zp, image_t * img);

// ----------------- IMAGE -----------------------
image_t * image_creer(int lignes, int colonnes, int rowtride);

void afficher_image(image_t * image);

// ----------------- PIXEL -----------------------
pixel_t * pixel_creer(uint8_t r, uint8_t g, uint8_t b);

void setPixel(image_t* i, int x, int y, uint8_t r, uint8_t g, uint8_t b);
