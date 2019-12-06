#ifndef SROSSLER
#define SROSSLER

void setup_rossler(FILE*file, point p);
void param_init_rossler(FILE*v);
void traj_p(FILE*file, FILE*v,FILE*f,point p);
void vitesse_systeme_rossler(FILE*v,FILE*f,FILE*vit);
#endif