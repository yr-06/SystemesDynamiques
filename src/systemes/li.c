#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "li.h"

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
FILE*f;
f=fopen("li.dat","w+");



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

float traj_p(point p)
{
	float dx=sigma*(p.y-p.x)*dt;
	float dy=(p.x*((rho-p.z)-p.y))*dt;
	float dz=(p.x*p.y-beta*p.z)*dt;
	float n=tmax/dt;
    float temps;
	int c=ceil(n);
    int r=floor(n);
    for (int i=0;i<c; i++)
	{
		if (i=0)
			{
				 fprintf(f,"%f\t %f\t %f\t %f\n", temps,x,y,z);
			}
	
			else 
			{
				x=p.x+i*dx;
				y=p.y+i*dy;
				z=p.z+i*dz;
            	temps=i*dt;
            	fprintf(f,"%f\t %f\t %f\t %f\n", temps,x,y,z);
				
			}
		
			if ((r*dt)!=tmax)
			{
				x=p.x+c*dx;
				y=p.y+c*dy;
				z=p.z+c*dz;
                temps=c*dt;
                fprintf(f,"%f %f %f %f\n", temps,x,y,z);
			}
		}
		fclose(f);
	}
}

 
