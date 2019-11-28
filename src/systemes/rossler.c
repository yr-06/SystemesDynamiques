#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Equation de Rossler:
dx/dt=-y-z
dy/dt=x+ay
dz/dt=b+z(x-c)
*/

/*Valeurs de a, b, c possibles:
a=0.2 ou 0.1
b=0.2 ou 0.1
c=5.7 ou c=14*/ 

float param_init(){
	
	float a;
	float b;
	float c;
	
	printf("Entrez la valeur de a")
	scanf("%f", &a);
	printf("/n")
	
	printf("Entrez la valeur de b")
	scanf("%f", &b);
	printf("/n")
	
	printf("Entrez la valeur de c")
	scanf("%f", &c)
	
	return a, b, c;
}


