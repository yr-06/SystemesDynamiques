#ifndef __point__
#define __point__

struct point3D {
	float x;
	float y;
	float z;
};
  
typedef struct point3D point;

void init_points(point*p);

#endif