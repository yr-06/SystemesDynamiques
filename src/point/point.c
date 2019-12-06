#include <stdio.h>
#include <stdlib.h>
#include "../include/point.h"

point init_points(point *p){
	printf("Définir les coordonnées initiales : \nx= ");
	scanf("%f", p->x);
	
	printf("%f %f %f/n", p->x, p->y, p->z);
	
	printf("y= ");
	scanf("%f", p->y);
	
	printf("%f %f %f/n", p->x, p->y, p->z);
	
	printf("z= ");
	scanf("%f", p->z);
	
	printf("%f %f %f/n", p->x, p->y, p->z);
	
	printf("Coordonnées du point: %f %f %f\n",(*p).x, (*p).y, (*p).z);
	
}
