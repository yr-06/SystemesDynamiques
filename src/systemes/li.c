#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Equations de Li:
dx/dt=a(y-x)+dxz
dy/dt=kx+fy-xz
dz/dt=cz+xy-ex**2
*/

/*Valeurs de a,c,d,e,k,f:
a=41
c=11
d=0.16
e=0.65
k=55
f=20
*/


float init_param(){
	float a;
	float c;
	float d;
	float e;
	float k;
	float f;
	
	printf("Entrez la valeur de a")};
	scanf("%f", &a)
	printf("/n")
	
	printf("Entrez la valeur de c")};
	scanf("%f", &c)
	printf("/n")
	
	printf("Entrez la valeur de d")};
	scanf("%f", &d)
	printf("/n")
	
	printf("Entrez la valeur de e")};
	scanf("%f", &e)
	printf("/n")
	
	printf("Entrez la valeur de k")};
	scanf("%f", &k)
	printf("/n")
	
	printf("Entrez la valeur de f")};
	scanf("%f", &f)
	printf("/n")
	
	return a, c, d, e, k, f;
	
}