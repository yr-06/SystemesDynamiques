#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/point.h"
#include "../include/temps.h"
#include "../include/li.h"

/*Equations de Li:
dx/dt=a*(y-x)+d*x*z
dy/dt=k*x+f*y-x*z
dz/dt=c*z+x*y-e*x^2
*/

/*Valeurs de a,c,d,e,k,f:
a=41
c=11
d=0.16
e=0.65
k=55
f=20
*/

void setup_Li(FILE*file, FILE*p){
	
	FILE*g=NULL;
	FILE*v=NULL;
	g=fopen("li.dat","w+");
	v=fopen("Valeurs_li.txt","w+");
	init_param_li(v);
	traj_p_li(file, v,g,p);
	fclose(g);
	remove("Valeurs_li.txt");
	
}

void init_param_li(FILE *v){
	float a , c, d , e, k , f;
	
	printf("Entrez la valeur de a : a=");
	scanf("%f", &a);
	printf("\n");
	
	printf("Entrez la valeur de c: c=");
	scanf("%f", &c);
	printf("\n");
	
	printf("Entrez la valeur de d: d=");
	scanf("%f", &d);
	printf("\n");
	
	printf("Entrez la valeur de e: e=");
	scanf("%f", &e);
	printf("\n");
	
	printf("Entrez la valeur de k: k=");
	scanf("%f", &k);
	printf("\n");
	
	printf("Entrez la valeur de f: f=");
	scanf("%f", &f);
	printf("\n");
	
	fprintf(v,"%f %f %f %f %f %f",a, c, d, e, k, f);
	
}

void traj_p_li(FILE*file, FILE*v,FILE*g, FILE*p){
	fseek(file,0,SEEK_SET);
	fseek(v,0,SEEK_SET);
	fseek(p,0,SEEK_SET);
	float a, c, d, e, k, f;
	fscanf(v, "%f %f %f %f %f %f", &a, &c, &d, &e, &k, &f);
	float tmax, dt;
	fscanf(file, "%f %f", &tmax, &dt);
	float px,py,pz;
	fscanf(p,"%f %f %f", &px, &py, &pz);
	float x,y,z,vit,vx,vy,vz;
	float dx=(a*(py-px)+d*px*pz)*dt;
	float dy=(k*px+f*py-px*px*pz)*dt;
	float dz=(c*pz+px*py-e*pow(px,2))*dt;
	float n=tmax/dt;
    float temps;
	int ce=ceil(n);
	
    for (int i=0;i<=ce; i++) 
    {
		fseek(g,0,SEEK_END);
		x=px+i*dx;
		y=py+i*dy;
		z=pz+i*dz;
		vx=a*(y-x)+d*x*z;
		vy=k*x+f*y-x*z;
		vz=c*z+x*y-e*pow(x,2);
        temps=i*dt;
        vit=sqrt(pow(vx,2)+pow(vy,2)+pow(vz,2));
        fprintf(g,"%f\t %f\t %f\t %f\t %f\n", temps,x,y,z,vit);
				
		}
		
	if (ce!=n)
	{
		fseek(g,0,SEEK_END);
		x=px+n*dx;
		y=py+n*dy;
		z=pz+n*dz;
		vx=a*(y-x)+d*x*z;
		vy=k*x+f*y-x*z;
		vz=c*z+x*y-e*pow(x,2);
        vit=sqrt(pow(vx,2)+pow(vy,2)+pow(vz,2));
        fprintf(g,"%f\t %f\t %f\t %f\t %f\n", tmax,x,y,z,vit);
	}
	
}

