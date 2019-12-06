#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/point.h"
#include "../include/lorenz.h"


/* Eq de Lorenz

(dx/dt)= sigma*(p.y-p.x)
(dy/dt)=p.x*(rho-p.z)-p.y
(dz/dt)=p.x*p.y-beta*p.z
*/
 
void setupLorenz(FILE*file, point p) {
	FILE*f=NULL;
	FILE*v=NULL;
	FILE*vit=NULL;
	f=fopen("lorenz.dat","w+");
	v=fopen("Valeurs_lor.txt","w+");
	vit=fopen("vitesse_lorenz.dat","w+");
	
	param_init_lorenz(v);
	traj_p(file,v,f,p);
	vitesse_systeme_lorenz(v,f,vit);
	
	fclose(v);
	fclose(f);
	fclose(vit);
}

void param_init_lorenz(FILE*v) {	
	float sigma, rho, beta;
	
	printf ("Entrez une valeur sigma");
	scanf("%f", &sigma);
	printf("\n");
	
	printf ("Entrez une valeur rho");
	scanf("%f", &rho);
	printf("\n");
	
	printf ("Entrez une valeur beta");
	scanf("%f", &beta);
	
	fprintf(v,"%f %f %f",sigma,rho,beta);
}

	

void traj_p(FILE*file, FILE*v,FILE*f,point p){
	float sigma,rho, beta,x,y,z,dt,tmax;
	float dx=(sigma*(p.y-p.x))*dt;
	float dy=(((p.x)*(rho-p.z))-p.y)*dt;
	float dz=((p.x*p.y)-beta*p.z)*dt;
	float n=tmax/dt;
    float temps;
	int c=ceil(n);
    int r=floor(n);
    fscanf(v,"%f %f %f",&sigma,&rho,&beta);
	fscanf(file,"%f %f", &tmax, &dt);
    
    for (int i=0;i<c; i++) {
		x=p.x+i*dx;
		y=p.y+i*dy;
		z=p.z+i*dz;
        temps=i*dt;
        fprintf(f,"%f\t %f\t %f\t %f\n", temps,x,y,z);
 	}

				
	if ((r*dt)!=tmax) {
		x=p.x+n*dx;
		y=p.y+n*dy;
		z=p.z+n*dz;
        temps=tmax;
        fprintf(f,"%f\t %f\t %f\t %f\n", temps,x,y,z);           
	}
}

void vitesse_systeme_lorenz(FILE*v,FILE*f,FILE*vit){
	float sigma,rho,beta;
	float x, y, z, vx, vy, vz, module; 
	float temps;
    fscanf(v,"%f %f %f",&sigma,&rho,&beta);
    
	while(!feof(f))
   {	fscanf(f,"%f\t %f\t %f\t %f\n",&temps,&x,&y,&z);
    	vx=sigma*(y-x);
    	vy=x*(rho-z)-y;
    	vz=x*y-beta*z;
    	module=sqrt(pow(vx,2)+pow(vy,2)+pow(vz,2));
    	fprintf(vit,"%f\t %f\t %f\t %f\t", temps,vx,vy,vz);
    	fprintf(vit,"%f\n",module);
    	
    }
  }
    
	/*for (int i=0;i<=c; i++)
	{
		if (i=0) {
			
			vx=sigma*(p.y-p.x);
	 		vy=p.x*(rho-p.z)-p.y;
	 		vz=p.x*p.y-beta*p.z;
	 		temps=i*dt
			module=sqrt(pow(vx,2)+pow(vy,2)+pow(vz,2));
			fprintf(vit,"%.3f\t %.3f\t %.3f\t %.3f\t %.3f\n", temps,vx,vy,vz,module);
		}
		
		else 
		{
			vx=vx+i*dx/dt;				
			vy=vy+i*dy/dt;
			vz=vz+i*dz/dt;
            temps=i*dt;
            fprintf(vit,"%f\t %f\t %f\t %f\t %f\n", temps,vx,vy,vz, module);
        }

				
	}*/
	/* ENCORE CE DOUBLON
	if ((r*dt)!=tmax)
	{
		vx=vx+c*dx/dt;
		vy=vy+c*dy/dt;
		vz=vz+c*dz/dt;
        temps=n*dt;
        fprintf(f,"%f %f %f %f %f\n", temps,vx,vy,vz, module);
	}*/
