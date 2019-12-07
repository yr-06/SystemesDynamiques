#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/point.h"
#include "../include/temps.h"
#include "../include/rossler.h"

/*Equation de Rossler:
dx/dt=-y-z
dy/dt=x+ay
dz/dt=b+z(x-c)
*/

/*Valeurs de a, b, c possibles:
a=0.2 ou 0.1
b=0.2 ou 0.1
c=5.7 ou c=14

*/ 

void setup_rossler(FILE*file, FILE*p){

	FILE*f=NULL;
	FILE*v=NULL;
	f=fopen("rossler.dat","w+");
	v=fopen("Valeurs_ross.txt","w+");
	
	param_init_rossler(v);
	traj_p_r(file,v,f,p);
	fclose(f);
	remove("Valeurs_ross.txt");
}

void param_init_rossler(FILE*v){
	
	float a,b,c;
	
	printf("Entrez la valeur de a: a=");
	scanf("%f", &a);
	printf("/n");
	
	printf("Entrez la valeur de b: b=");
	scanf("%f", &b);
	printf("/n");
	
	printf("Entrez la valeur de c: c=");
	scanf("%f", &c);
	fprintf(v,"%f %f %f\n",a,b,c);
}

void traj_p_r(FILE*file, FILE*v,FILE*f,FILE*p)
{
	fseek(file,0,SEEK_SET);
	fseek(v,0,SEEK_SET);
	fseek(p,0,SEEK_SET);
	float a,b,c;
	fscanf(v,"%f %f %f",&a,&b,&c);
	float tmax,dt;
	fscanf(file,"%f %f", &tmax, &dt);
	float px,py,pz,vx,vy,vz,vit;
	fscanf(p,"%f %f %f", &px, &py, &pz);
	float x,y,z ;
	float dx=(-py-pz)*dt;
	float dy=(px+a*py)*dt;
	float dz=(b+(pz*px-c))*dt;
	float n=tmax/dt;
    float temps;
	int h=ceil(n);
    int r=floor(n);
    for (int i=0;i<h; i++)
	{
		fseek(f,0,SEEK_END);
		x=px+i*dx;
		y=py+i*dy;
		z=pz+i*dz;
		vx=-y-z;
		vy=x+a*y;
		vz=b+z*(x-c);
		vit=sqrt(pow(vx,2)+pow(vy,2)+pow(vz,2));
        temps=i*dt;
        fprintf(f,"%f\t %f\t %f\t %f\t %f\n", temps,x,y,z,vit);
        
				
	}
		
	if ((h*dt)!=tmax)
	{
		fseek(f,0,SEEK_END);
		x=px+n*dx;
		y=py+n*dy;
		z=pz+n*dz;
		vx=-y-z;
		vy=x+a*y;
		vz=b+z*(x-c);
        vit=sqrt(pow(vx,2)+pow(vy,2)+pow(vz,2));
        fprintf(f,"%f\t %f\t %f\t %f\t %f\n", temps,x,y,z,vit);
       
        
	}
}
