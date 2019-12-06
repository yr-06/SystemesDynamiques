#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/point.h"
#include "../include/lorenz.h"
#include "../include/li.h"
#include "../include/rossler.h"

void init_temps(FILE *file){
	float dt;
	float tmax;
	printf("Entrez la valeur de tmax:");
	scanf("%f", &tmax);
	printf("Entrez la valeur de dt:");
	scanf("%f", &dt);
	if(dt>tmax)
	{
		printf("Cette valeur est superieur au temps maximal\n");
		printf("Veuiller entrer de nouvelles valeurs :\n");
		init_temps(file);
	}
	else	
	{
		//fseek(file, SEEK_END);
		fprintf(file,"%f %f\n", tmax, dt);
	}
}

void choix_systemes(FILE *file, point p){
	int systeme;
	float dt,tmax;
	printf("1 = Système de Lorenz \n");
	printf("2 = Système de Rossler\n");
	printf("3 = Système de Li\n");
	printf("Quel système voulez-vous choisir ? Rentrez un nombre : ");
	scanf("%d", &systeme);
	fscanf(file, "%f %f", &tmax, &dt);
	
	if (systeme == 1){
		printf("Vous avez choisi le système de Lorentz. \n");
		SLORENZsetupLorenz(p);
		
	} if (systeme == 2){
		printf("Vous avez choisi le système de Rossler. \n");
		SROSSLERsetup_rossler(p);
		
		
	} if (systeme == 3){
		printf("Vous avez choisi le système de Li. \n");
		SLIsetup_Li(p);
		
	}
	else 
	{
		printf("Ce système n'existe pas. \n");
		choix_systemes(file, p);
	}
}

int main(int argc, char *argv[]){
	FILE*file=NULL;
	//FILE*result=NULL;
	file=fopen("paraminit.txt","w+");
	//result=fopen("Courbe.jpeg","w+");
	
	point p;
	init_points(&p);
	printf("Coordonnées du point: %.2f %.2f %.2f \n", p.x, p.y, p.z);
	
	printf("---\n");
	
	
	init_temps(file);
	choix_systemes(file, p);
	fclose(file);
}