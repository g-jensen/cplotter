#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "vector.h"

typedef struct Circle Circle;

Circle* circle_create();
void circle_destroy(Circle* circle);

Vec2f circle_pos(Circle* circle);
float circle_radius(Circle* circle);

void circle_set_pos(Circle* circle, Vec2f position);
void circle_set_radius(Circle* circle, float radius);

#endif