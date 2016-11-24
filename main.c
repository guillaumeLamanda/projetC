#include <limits.h>
#include <stdio.h>
#include <stdarg.h>

#include "zpixel.h"

int main(void) {
	// Init
	printf("Creation des zpixels...");
	zpixel_t * zpix1 = zpixel_creer(0, 0, 3);
	zpixel_t * zpix2 = zpixel_creer(0, 0, 3);
	if(zpix1 != NULL && zpix2 != NULL){
		printf("OK\n");
		printf("Initialisation des zpixel...\n");
		zpixel_initialiser(zpix1, 123,230,12);
		zpixel_initialiser(zpix2, 12,120,80);

		// zp1
		printf("Zpixel1 :\n\tr: %d\n\tg: %d\n\tb: %d\n", zpix1->rgb.r, zpix1->rgb.g, zpix1->rgb.b);
		printf("\tMax : %d\n\tMin : %d\n", max(zpix1), min(zpix1));
		// zp2
		printf("Zpixel2 :\n\tr: %d\n\tg: %d\n\tb: %d\n", zpix2->rgb.r, zpix2->rgb.g, zpix2->rgb.b);
		printf("\tMax : %d\n\tMin : %d\n\n", max(zpix2), min(zpix2));

		// Distance
		printf("Distance : %lf\n", distance(zpix1, zpix2));


	}
	else {
		printf("Erreur\n");
	}

	return 0;
}
