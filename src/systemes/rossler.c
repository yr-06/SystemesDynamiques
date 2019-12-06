#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/point.h"
#include "../include/rossler.h"

/*Equation de Rossler:
dx/dt=-y-z
dy/dt=x+ay
dz/dt=b+z(x-c)
*/

/*Valeurs de a, b, c possibles:
a=0.2 ou 0.1
b=0.2 ou 0.1
c=5.7 ou c=14*/ 

void setup_rossler(FILE*file, point p){

	FILE*f=NULL;
	FILE*v=NULL;
	FILE*vit=NULL;
	f=fopen("rossler.dat","w+");
	v=fopen("Valeurs_ross.txt","w+");
	vit=fopen("vitesse_rossler.dat","w+");
	
	param_init_rossler(v);
	traj_p(file,v,f,p);
	vitesse_systeme_rossler(v,f,vit);
	
	fclose(v);
	fclose(f);
	fclose(vit);
	//set parametric;
	//gnuplot(f);
}

void param_init_rossler(FILE*v){
	
	float a,b,c;
	
	printf("Entrez la valeur de a:");
	scanf("%f", &a);
	printf("/n");
	
	printf("Entrez la valeur de b:");
	scanf("%f", &b);
	printf("/n");
	
	printf("Entrez la valeur de c");
	scanf("%f", &c);
	fprintf(v,"%f %f %f\n",a,b,c);
}

void traj_p(FILE*file, FILE*v,FILE*f,point p)
{	float a,b,c,x,y,z,dt,tmax;
	float dx=(-p.y-p.z)*dt;
	float dy=(p.x+a*p.y)*dt;
	float dz=(b+(p.z*p.x-c))*dt;
	float n=tmax/dt;
    float temps;
	int h=ceil(n);
    int r=floor(n);
    fscanf(v,"%f %f %f",&a,&b,&c);
    fscanf(file,"%f %f", &tmax, &dt);
    
    for (int i=0;i<h; i++)
	{
		x=p.x+i*dx;
		y=p.y+i*dy;
		z=p.z+i*dz;
        temps=i*dt;
        fprintf(f,"%f\t %f\t %f\t %f\n", temps,x,y,z);
				
	}
		
	if ((r*dt)!=tmax)
	{
		x=p.x+n*dx;
		y=p.y+n*dy;
		z=p.z+n*dz;
        temps=tmax;
        fprintf(f,"%f\t %f\ %f\t %f\n", temps,x,y,z);
	}
}
	
void vitesse_systeme_rossler(FILE*v,FILE*f,FILE*vit){
	float a,b,c;
	float x, y, z, vx, vy, vz, module; 
	float temps;
    fscanf(v,"%f %f %f",&a,&b,&c);
 
	while(!feof(f))
   {	fscanf(f,"%f\t %f\t %f\t %f\n",&temps,&x,&y,&z);
    	vx=-y-z;
    	vy=x+a*y;
    	vz=b+z*(x-c);
    	module=sqrt(pow(vx,2)+pow(vy,2)+pow(vz,2));
    	fprintf(vit,"%f\t %f\t %f\t %f\t", temps,vx,vy,vz);
    	fprintf(vit,"%f\n",module);
    	
    }
  }	


/*void vitesse_systeme_rossler(FILE*v,point *p){
	float a,b,c ;
	fscanf(v,"%f %f %f",&a,&b,&c);

	float vx, vy,vz, module; 
	
	float n=tmax/dt;
    float temps=0;
	int c=ceil(n);
    int r=floor(n);
    
    for (int i=0;i<c; i++)
	{
		if (i=0)
			{
				vx=-p.y-p.z;
	 			vy=p.x+a*p.y;
	 			vz=b+p.z(p.x-c);
	 			module=sqrt(pow(vx,2)+pow(vy,2)+pow(vz,2));
				fprintf(f,"%.3f\t %.3f\t %.3f\t %.3f\t %.3f\n", temps,vx,vy,vz,module);
			}
	
			else 
			{
				vx=vx+i*dx/dt;
				vy=vy+i*dy/dt;
				vz=vz+i*dz/dt;
            	temps=i*dt;
            	fprintf(f,"%f\t %f\t %f\t %f\t %f\n", temps,vx,vy,vz, module);
				
			}
		
			if ((r*dt)!=tmax)
			{
				vx=vx+c*dx/dt;
				vy=vy+c*dy/dt;
				vz=vz+c*dz/dt;
                temps=c*dt;
                fprintf(f,"%f %f %f %f %f\n", temps,vx,vy,vz, module);
			}
		}
		fclose(f);
	}
*/