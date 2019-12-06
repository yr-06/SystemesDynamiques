#include <stdio.h>
#include <stdlib.h>
#include "../include/point.h"

void init_points(point *p){
	printf("Définir les coordonnées initiales : \nx= ");
	scanf("%f", (*p).x);
	printf("y= ");
	scanf("%f", (*p).y);
	printf("z= ");
	scanf("%f", (*p).z);
	printf("Coordonnées du point: %f %f %f \n",(*p).x, (*p).y,(*p).z);
	return p;
}
