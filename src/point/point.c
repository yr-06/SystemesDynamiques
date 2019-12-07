#include <stdio.h>
#include <stdlib.h>
#include "../include/point.h"

void init_points(FILE*p){
	float px, py, pz;
	printf("Entrez une coordonnée selon x : x=");
	scanf("%f",&px);
	printf("\n");
	
	printf("Entrez une coordonnée selon y : y=");
	scanf("%f",&py);
	printf("\n");
	
	printf("Entrez une coordonnée selon z : z=");
	scanf("%f",&pz);
	printf("\n");
	
	
	fprintf(p,"%f %f %f", px, py,pz);
	
}
