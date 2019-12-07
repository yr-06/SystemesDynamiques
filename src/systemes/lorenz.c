#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/point.h"
#include "../include/temps.h"
#include "../include/lorenz.h"


/* Eq de Lorenz

(dx/dt)= sigma*(py-px)
(dy/dt)=px*(rho-pz)-py
(dz/dt)=px*py-beta*pz
*/
 
void setupLorenz(FILE*file, FILE*p) {
	FILE*f=NULL;
	FILE*v=NULL;
	f=fopen("lorenz.dat","w+");
	v=fopen("Valeurs_lor.txt","w+");
	
	param_init_lorenz(v);
	traj_p_lo(file,v,f,p);
	fclose(f);
	remove("Valeurs_lor.txt");
	
}

void param_init_lorenz(FILE*v) {	
	float sigma, rho, beta;
	
	printf ("Entrez une valeur sigma : sigma =");
	scanf("%f", &sigma);
	printf("\n");
	
	printf ("Entrez une valeur rho : rho =");
	scanf("%f", &rho);
	printf("\n");
	
	printf ("Entrez une valeur beta : beta =");
	scanf("%f", &beta);
	
	fprintf(v,"%f %f %f",sigma,rho,beta);
}

	

void traj_p_lo(FILE*file, FILE*v,FILE*f,FILE*p){
	fseek(file,0,SEEK_SET);
	fseek(v,0,SEEK_SET);
	fseek(p,0,SEEK_SET);
	float sigma, rho, beta;
	fscanf(v,"%f %f %f",&sigma,&rho,&beta);
	float tmax , dt;
	fscanf(file,"%f %f", &tmax, &dt);
	float px , py , pz, vit;
	fscanf(p,"%f %f %f", &px, &py, &pz);
    
	float x , y , z; 
	float dx=(sigma*(py-px))*dt;
	float dy=(((px)*(rho-pz))-py)*dt;
	float dz=((px*py)-beta*pz)*dt;
	float vx,vy,vz;
	float n=tmax/dt;
    float temps;
	int h=ceil(n);
   
    for (int i=0;i<=h; i++) {
    	fseek(f,0,SEEK_END);
		x=px+i*dx;
		y=py+i*dy;
		z=pz+i*dz;
		vx=sigma*(y-x);
		vy=x*(rho-z)-y;
		vz=x*y-beta*z;
        temps=i*dt;
        vit=sqrt(pow(vx,2)+pow(vy,2)+pow(vz,2));
        fprintf(f,"%f\t %f\t %f\t %f\t %f\n", temps,x,y,z,vit);
 	}
		
	if (h!=n) {
		fseek(f,0,SEEK_END);
		x=px+n*dx;
		y=py+n*dy;
		z=pz+n*dz;
		vx=sigma*(y-x);
		vy=x*(rho-z)-y;
		vz=x*y-beta*z;
		vit=sqrt(pow(vx,2)+pow(vy,2)+pow(vz,2));
        fprintf(f,"%f\t %f\t %f\t %f\t %f\n",tmax,x,y,z,vit);           
	}
}

