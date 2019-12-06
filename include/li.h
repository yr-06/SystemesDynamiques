#ifndef SLI
#define SLI

void setup_Li(FILE*file, point p);
void init_param_li(FILE *v);
void traj_p(FILE*file, FILE*v,FILE*g,point p);
void vitesse_systeme_li(FILE*v,FILE*g,FILE*vit);


#endif