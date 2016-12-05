#include <limits.h>
#include <stdio.h>
#include <stdarg.h>

#include "zpixel.h"

int main(void) {
	// Init
	printf("Creation des zpixels...");
	zpixel_t * zpix1 = zpixel_creer(0, 0, 3);
	zpixel_t * zpix2 = zpixel_creer(0, 0, 3);
	zpixel_t * zpix3 = zpixel_creer(2, 2, 3);

	if(zpix1 != NULL && zpix2 != NULL ){
		printf("OK\n");
		printf("Initialisation des zpixel...\n");
		zpixel_initialiser(zpix1, 255,255,255);
		zpixel_initialiser(zpix2, 0,0,0);
		zpixel_initialiser(zpix3, 15,157,232);

		// zp1
		printf("Zpixel1 blanc :\n\tr: %d\n\tg: %d\n\tb: %d\n", zpix1->rgb.r, zpix1->rgb.g, zpix1->rgb.b);
		printf("\tMax : %d\n\tMin : %d\n\tLuminosite : %lf\n\tSaturation : %lf\n\n", max(zpix1), min(zpix1), luminosite(zpix1), saturation(zpix1));
		// zp2
		printf("Zpixel2 noir :\n\tr: %d\n\tg: %d\n\tb: %d\n", zpix2->rgb.r, zpix2->rgb.g, zpix2->rgb.b);
		printf("\tMax : %d\n\tMin : %d\n\tLuminosite : %lf\n\tSaturation : %lf\n\n", max(zpix2), min(zpix2), luminosite(zpix2), saturation(zpix2));

		// Zpixel quelconque
		printf("Zpixel3 quelconque :\n\tr: %d\n\tg: %d\n\tb: %d\n", zpix3->rgb.r, zpix3->rgb.g, zpix3->rgb.b);
		printf("\tMax : %d\n\tMin : %d\n\tLuminosite : %lf\n\tSaturation : %lf\n\n", max(zpix3), min(zpix3), luminosite(zpix3), saturation(zpix3));


		// Distance
		printf("Distance : %lf\n", distance(zpix1, zpix2));

		// Enregistrement des pixels
		// pixel_t pixels[24] ;
		image_t * image1 = image_creer(8, 8, 25);

		printf("----- Image avant projection : \n");
		afficher_image(image1);

		// zpix3->position.x=3;
		// zpix3->position.y=3;

		projection(zpix3,image1);

		printf("----- Image apres projection : \n");
		afficher_image(image1);
	}
	else {
		printf("Erreur\n");
	}

	return 0;
}
