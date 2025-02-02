#ifndef _VECTOR_H_
#define _VECTOR_H_

#define __USE_MATH_DEFINES
#include <math.h>

typedef struct Vec2f {
  float x;
  float y;
} Vec2f;

typedef struct Vec2i {
  int x;
  int y;
} Vec2i;

Vec2f vector_add(Vec2f point1, Vec2f point2);
Vec2f vector_sub(Vec2f point1, Vec2f point2);
Vec2f vector_mult(float scalar, Vec2f point);
float vector_distance(Vec2f point1, Vec2f point2);
int vector_equals(Vec2f point1, Vec2f point2);
float vector_magnitude(Vec2f point1);
Vec2f vector_normalize(Vec2f point1);

#endif
