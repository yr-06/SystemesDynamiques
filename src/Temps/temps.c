#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/point.h"
#include "../include/temps.h"

void init_temps(FILE *file){
	float dt;
	float tmax;
	printf("Entrez la valeur de tmax en secondes :");
	scanf("%f", &tmax);
	printf("Entrez la valeur de dt en secondes :");
	scanf("%f", &dt);
	if(dt>tmax)
	{
		printf("Cette valeur est superieure  au temps maximal\n");
		printf("Veuillez entrer de nouvelles valeurs :\n");
		init_temps(file);
	}
	else	
	{
		fseek(file,0, SEEK_END);
		fprintf(file,"%f %f\n", tmax, dt);
	}
}