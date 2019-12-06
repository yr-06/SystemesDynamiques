#ifndef SLORENZ
#define SLORENZ

void setupLorenz(FILE*file, point p);
void param_init_lorenz(FILE*v);
void traj_p(FILE*file, FILE*v,FILE*f,point p);
void vitesse_systeme_lorenz(FILE*v,FILE*f,FILE*vit);

#endif