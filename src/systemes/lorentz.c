#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Eq de Lorentz

(dx/dt)= sigma*(p.y-p.x)
(dy/dt)=p.x*(rho-p.z)-p.y
(dz/dt)=x*y-beta*p.z
*/
 
float dt =0.03;
float tmax=15;

void setupLorentz(point p)

float param_init()//float dt; float sigma ; float rho ; float beta 
{
	
	float sigma ;
	float rho ; 
	float beta ;
	printf ("Entrez un incrément de temps");
	scanf("%.f", &dt);
	printf("\n");
	
	printf ("Entrez une valeur sigma");
	scanf("%f", &sigma);
	printf("\n");
	
	printf ("Entrez une valeur rho");
	scanf("%f", &rho);
	printf("\n");
	
	printf ("Entrez une valeur beta");
	scanf("%f", &beta);
	return sigma , rho, beta;
}

float traj_p(float p.x, float p.y, float p.z)
{
	float dx=sigma*(p.y-p.x)*dt;
	float dy=(p.x*((rho-p.z)-p.y))*dt;
	float dz=(x*y-beta*p.z)*dt;
	float n=tmax/dt;
	int c=ceil(n);
	int r=floor(n)
	float t[c][3]
	for (int i=0; i<c ; i++)
	{
		if (i=0)
		{
			t[0][1]=p.x;
			t[0][2]=p.y;
			t[0][3]=p.z;
		}
		
		else 
		{
			
			t[i][1]=p.x+i*dx;
			t[i][2]=p.y+i*dy;
			t[i][3]=p.z+i*dz;
				
		}
	}
	if ((r*dt)!=tmax)
		{
				t[c][1]=p.x+c*dx;
				t[c][2]=p.y+c*dy;
				t[c][3]=p.z+c*dz;				
		}
		
	return t;
}
int main( int argc, char * argv[])
{
	res=traj_p(0., float p.y, float p.z)
}
/*...vit_p(point p)
{
	
}
*/



