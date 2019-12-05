#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../libs/libpoint.a"
#include "../include/lorenz.h"

/* Eq de Lorentz

(dx/dt)= sigma*(p.y-p.x)
(dy/dt)=p.x*(rho-p.z)-p.y
(dz/dt)=x*y-beta*p.z
*/
 
void setupLorentz(point p) {
	FILE*f;
	FILE*v;
	f=fopen("lorenz.dat","w+");
	v=fopen("Valeurs.txt","w+");
	param_init_lorenz();
	traj_p(p);
	fclose(f);
	vitesse(p);
	set parametric;
	gnuplot(f);
	
}

float param_init_lorenz()
{
	
	float sigma,rho, beta ;
	
	printf ("Entrez une valeur sigma");
	scanf("%f", &sigma);
	printf("\n");
	
	printf ("Entrez une valeur rho");
	scanf("%f", &rho);
	printf("\n");
	
	printf ("Entrez une valeur beta");
	scanf("%f", &beta);
	fprintf(v,*sigma,*rho,*beta);
	return sigma , rho, beta;
}

	

float traj_p(point p)
{
	float sigma,rho, beta,x,y,z;
	fscanf(v,"%f %f %f",&sigma,&rho,&beta);
	float dx=sigma*(((*p).y)-((*p).x))*dt;
	float dy=(((*p).x)*((rho-((*p).z))-((*p).y)))*dt;
	float dz=(((*p).x)*((*p).y)-beta*((*p).z))*dt;
	float n=tmax/dt;
    float temps;
	int c=ceil(n);
    int r=floor(n);
    
    for (int i=0;i<c; i++)
	{
		x=(*(p).x)+i*dx;
		y=(*(p).y)+i*dy;
		z=(*(p).z)+i*dz;
        temps=i*dt;
        fprintf(f,"%f\t %f\t %f\t %f\n", temps,x,y,z);
 	}

				
	if ((r*dt)!=tmax)
	{
		x=(*(p).x)+c*dx;
		y=(*(p).y)+c*dy;
		z=(*(p).z)+c*dz;
        temps=c*dt;
        fprintf(f,"%f\t %f\t %f\t %f\n", temps,x,y,z);
                
	}
	
}


/*void vitesse_systeme_lorenz(){
	float sigma,rho,beta ;
	fscanf(v,"%f %f %f",&sigma,&rho,&beta);

	float vx, vy,vz, module; 
	
	float n=tmax/dt;
    float temps=0;
	int c=ceil(n);
    int r=floor(n);
    
    for (int i=0;i<c; i++)
	{
		if (i=0)
			{
				vx=sigma*(p.y-p.x);
	 			vy=p.x*(rho-p.z)-p.y;
	 			vz=p.x*p.y-beta*p.z;
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

