#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/point.h"
#include "../include/li.h"

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

void setup_Li(point *p){
	
	FILE*f=NULL;
	FILE*v=NULL;
	FILE*vit=NULL;
	f=fopen("li.dat","w+");
	v=fopen("Valeurs_li.txt","w+");
	vit=fopen("vitesse_li.dat","w+");
	
	init_param_li(v);
	traj_p(f, v, p);
	
	//set parametric;
	//gnuplot(f);
	
}

void init_param_li(FILE *v){
	float a , c, d , e, k , f;
	
	printf("Entrez la valeur de a");
	scanf("%f", &a);
	printf("/n");
	
	printf("Entrez la valeur de c");
	scanf("%f", &c);
	printf("/n");
	
	printf("Entrez la valeur de d");
	scanf("%f", &d);
	printf("/n");
	
	printf("Entrez la valeur de e");
	scanf("%f", &e);
	printf("/n");
	
	printf("Entrez la valeur de k");
	scanf("%f", &k);
	printf("/n");
	
	printf("Entrez la valeur de f");
	scanf("%f", &f);
	printf("/n");
	
	fprintf(v,"%f %f %f %f %f %f",a, c, d, e, k, f);
	
}

void traj_p(FILE *file, FILE *v, point p) {
	float a, c, d, e, k, f, tmax, dt;
	fscanf(v, "%f %f %f %f %f %f", a, c, d, e, k, f);
	fscanf(file, "%f %f", &tmax, &dt);
	float dx=(a*(p.y-p.x)+d*p.x*p.z)*dt;
	float dy=(k*p.x+f*p.y-p.x*p.x*p.z)*dt;
	float dz=(c*p.z+p.x*p.y-e*pow(p.x,2))*dt;
	float n=tmax/dt;
    float temps;
	int ce=ceil(n);
    for (int i=0;i<ce; i++) {
		if (i==0) {
			fprintf(file,"%f\t %f\t %f\t %f\n", temps, p.x, p.y, p.z);
		}
		else 
		{
			p.x=p.x+i*dx;
			p.y=p.y+i*dy;
			p.z=p.z+i*dz;
           	temps=i*dt;
           	fprintf(file,"%f\t %f\t %f\t %f\n", temps, p.x, p.y, p.z);
				
		}
		/* DOUBLON ALICIA FAUX
		if ((r*dt)!=tmax) {
			p.x=p.x+n*dx;
			p.y=p.y+n*dy;
			p.z=p.z+n*dz;
            temps=tmax;
            fprintf(file,"%f %f %f %f\n", temps, p.x, p.y, p.z);
		}*/
	}
	fclose(file);
}

void vitesse_systeme_li(FILE*file, FILE*v, point p){
	
	float sigma,rho,beta;
	float x, y, z, vx, vy, vz, module; 
	float n=tmax/dt;
    float temps;
	int c=ceil(n);
    int i=0;
    fscanf(v,"%f %f %f",&sigma,&rho,&beta);
    fscanf(file,"%f %f",&tmax,&dt);
	
    while(fscanf(f,"%f\t %f\t %f\t %f\n",&temps,&x,&y,&z)!=NULL) {
    	
    	if (i<c)
    	{
    		vx=sigma*(y-x);
    		vy=x*(rho-z)-y;
    		vz=x*y-beta*z;
    		module=sqrt(pow(vx,2)+pow(vy,2)+pow(vz,2));
    		fprintf(vit,"%f\t %f\t %f\t %f\t", temps,vx,vy,vz,module);
    		i++;
    	}
    }
  }
/*void vitesse_systeme_li(){
	float a , c, d , e, k , f;
	fscanf(v,"%f %f %f",&a , &c, &d ,&e, &k , &f);

	float vx, vy,vz, module; 
	
	float n=tmax/dt;
    float temps=0;
	int c=ceil(n);
    int r=floor(n);
    
    for (int i=0;i<c; i++)
	{
		if (i=0)
			{
				vx=a(p.y-p.x)+d*p.x*p.z;
	 			vy=k*p.x+f*p.y-p.x*p.z;
	 			vz=c*p.z+p.x*p.y-e*pow(p.x,2;
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

