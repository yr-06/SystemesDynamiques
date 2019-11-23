#include <stdio.h>

typedef struct point3D {
	float x;
	float y;
	float z;
} point;

point init_points(){
	point p;
	
	printf("Définir les coordonnées initiales : \nx= ");
	scanf("%f", &p.x);
	printf("y= ");
	scanf("%f", &p.y);
	printf("z= ");
	scanf("%f", &p.z);
	
	printf("Coordonnées du point: %.2f %.2f %.2f \n", p.x, p.y, p.z);
	return p;
}


void choix_systemes(point p){
	int systeme;
	printf("1 = Système de Lorentz \n");
	printf("Quel système voulez-vous choisir ? Rentrez un nombre : ");
	scanf("%d", &systeme);
	
	if (systeme == 1){
		printf("Vous avez choisi le système de Lorentz. \n");
		//on ajoutera la fonction plus tard
		
	}  else {
		printf("Ce système n'existe pas. \n");
		choix_systemes(p);
	}
}

int main(int argc, char* argv[]){
	point p = init_points();
	printf("---\n");
	choix_systemes(p);
}