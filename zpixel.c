#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

#include "zpixel.h"


// ----------------- ZPIXEL -----------------------
zpixel_t * zpixel_creer(int x, int y, int size){
  zpixel_t * zp = (struct zpixel*)malloc(sizeof(zp));
  if(zp == NULL) return NULL ;
  zp->position.x = x;
  zp->position.y = y;
  zp->size = size ;
  return zp ;
}

void zpixel_initialiser(zpixel_t *zp, int r, int g, int b){
  if (zp!=NULL){
    zp->rgb.r = r;
    zp->rgb.g = g;
    zp->rgb.b = b;
  }
}

int max(zpixel_t *zp){
  if((zp->rgb.r > zp->rgb.g) && (zp->rgb.r > zp->rgb.b)){
    return zp->rgb.r;
  }
  else if(zp->rgb.g > zp->rgb.b){
    return zp->rgb.g;
  }
  else {
    return zp->rgb.b;
  }
}

int min(zpixel_t *zp){
  if((zp->rgb.r < zp->rgb.g) && (zp->rgb.r < zp->rgb.b)){
    return zp->rgb.r;
  }
  else if(zp->rgb.g < zp->rgb.b){
    return zp->rgb.g;
  }
  else {
    return zp->rgb.b;
  }
}

double luminosite(zpixel_t *zp){
  double res = 0.0 ;
  if(zp != NULL){
    int m = max(zp);
    int n = min(zp);
    res = (m+n)/2;
  }
  return res ;
}

double saturation(zpixel_t *zp){
  double res = 0.0 ;
  if(zp != NULL){
    double lum = luminosite(zp);
    int m = max(zp);
    int n = min(zp);
    int maj = m-n;
    int min = m+n;
    if(lum == 0){

    }
    else if(lum<128){
      res =(double) maj/min ;
    }
    else{
      res = (double) (maj/(511-min));
    }
  }
  return res*255 ;
}

double distance(zpixel_t * zp1, zpixel_t * zp2){
  double res = 0.0 ;
  if(zp1 != NULL && zp2 != NULL){
    double res1 = pow((zp2->rgb.r - zp1->rgb.r), 2);
    double res2 = pow((zp2->rgb.g - zp1->rgb.g), 2);
    double res3 = pow((zp2->rgb.b - zp1->rgb.b), 2);
    res = sqrt(res1+res2+res3);
  }
  return res ;
}

void projection(zpixel_t * zp, image_t * img){
  int j,i ;
  // printf("Taille du zpix : %d", zp->size);
  for(i=0;i<zp->size;i++){
    for(j=0;j<zp->size;j++){
      // printf("position x: %d\nposition y:%d\n", zp->position.x, zp->position.y);
      setPixel(img, zp->position.x+i, zp->position.y+j, zp->rgb.r,zp->rgb.g,zp->rgb.b);
    }
  }
}

// ----------------- PIXEL -----------------------

pixel_t * pixel_creer(uint8_t r, uint8_t g, uint8_t b){
  pixel_t * pix = (struct pixel*)malloc(sizeof(pix));
  pix->r=r;
  pix->g=g;
  pix->b=b;

  return pix;
}

void setPixel(image_t* i, int x, int y, uint8_t r, uint8_t g, uint8_t b){
  // ligne y ou se trouve x
  // printf("Position : \n\trowstride:%d\n\ty:%d\n\tx:%d\n", i->rowstride, y, x);
  // printf("Adresse du pixel a placer : %d", adresseXY);
  // i->pixels[(i->rowstride * y) + x].r=r;
  // i->pixels[(i->rowstride * y) + x].g=g;
  // i->pixels[(i->rowstride * y) + x].b=b;
  // A faire verification débordement Image

  i->pixels[(i->rowstride * y) + x].r=r;
  i->pixels[(i->rowstride * y) + x].g=g;
  i->pixels[(i->rowstride * y) + x].b=b;
}

// ----------------- IMAGE -----------------------

image_t * image_creer(int lignes, int colonnes, int rowstride){
  image_t * img = (struct image*)malloc(sizeof(img));
  if(img == NULL) return NULL ;
  img->pixels = (pixel_t*)malloc(lignes*rowstride);
  // if(img->pixels == NULL) free(img) ; return NULL ;
  img->nblignes = lignes;
  img->nbcols =colonnes;
  img->rowstride = rowstride;
  return img ;
}

void afficher_image(image_t * image){
  for(int i=0; i<image->nblignes; i++){
    int y = i;
    for(int j=0; j<image->nbcols; j++){
      int x = j;
        printf(" (%d,%d,%d) \t|", image->pixels[(image->rowstride * y) + x].r,
          image->pixels[(image->rowstride * y) + x].g,image->pixels[(image->rowstride * y) + x].b);
    }
    printf("\n");
  }
}
