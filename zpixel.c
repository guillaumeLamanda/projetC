#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

#include "zpixel.h"

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
