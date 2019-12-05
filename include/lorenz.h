#ifndef SLORENTZ
#define SLORENTZ

void setupLorentz(point *p);
float param_init_lorenz(FILE* v);
float traj_p(FILE*v, FILE*f, point p);
void vitesse_systeme_lorenz(FILE*f, FILE*v, FILE*vit, point *p);

#endif