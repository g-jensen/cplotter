#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "vector.h"

typedef struct Rectangle Rectangle;

Rectangle* rectangle_create();
void rectangle_destroy(Rectangle* rectangle);

Vec2f rectangle_pos(Rectangle* rectangle);
Vec2f rectangle_size(Rectangle* rectangle);
float rectangle_rot(Rectangle* rectangle);

void rectangle_set_pos(Rectangle* rectangle, Vec2f position);
void rectangle_set_size(Rectangle* rectangle, Vec2f size);
void rectangle_set_rot(Rectangle* rectangle, float rotation);

#endif