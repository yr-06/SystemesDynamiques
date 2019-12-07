#ifndef SLORENZ
#define SLORENZ

void setupLorenz(FILE*file, FILE*p);
void param_init_lorenz(FILE*v);
void traj_p_lo(FILE*file, FILE*v,FILE*f,FILE*p);

#endif