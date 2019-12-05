#include <stdio.h>
#include <stdlib.h>
#include "../include/point.h"



point init_points(){
	point p;
	printf("Définir les coordonnées initiales : \nx= ");
	scanf("%f", p.x);
	printf("y= ");
	scanf("%f", p.y);
	printf("z= ");
	scanf("%f", p.z);
	

	return p;
}