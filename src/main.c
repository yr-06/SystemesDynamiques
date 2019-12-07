#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/point.h"
#include "../include/temps.h"
#include "../include/lorenz.h"
#include "../include/li.h"
#include "../include/rossler.h"

void choix_systemes(FILE *file, FILE*p){
	int systeme;
	float dt,tmax;
	printf("1 = Système de Lorenz \n");
	printf("2 = Système de Rossler\n");
	printf("3 = Système de Li\n");
	printf("Quel système voulez-vous choisir ? Rentrez un nombre : ");
	scanf("%d", &systeme);
	fscanf(file, "%f %f", &tmax, &dt);
	
	if (systeme == 1){
		printf("Vous avez choisi le système de Lorenz. \n");
		setupLorenz(file, p);
		
	} if (systeme == 2){
		printf("Vous avez choisi le système de Rossler. \n");
		setup_rossler(file, p);
		
		
	} if (systeme == 3){
		printf("Vous avez choisi le système de Li. \n");
		setup_Li(file, p);
		
	}
	else 
	{
		printf("Ce système n'existe pas. \n");
		printf("\n");
		choix_systemes(file, p);
	}
}

int main(int argc, char *argv[]){
	FILE*file=NULL;
	FILE*p=NULL;
	file=fopen("paraminit.txt","w+");
	p=fopen("Coord_p.txt","w+");
	init_points(p);
	init_temps(file);
	
	printf("---\n");
	
	choix_systemes(file,p);
	
		
}