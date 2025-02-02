#ifndef _RENDER_H_
#define _RENDER_H_

#include "points_config.h"
#include "shape.h"
#include "vector.h"
#include "window.h"

Rectangle* create_rectangle_between(Vec2f point1, Vec2f point2, float thickness);
void points_to_shapes(Vec2f* points, Shape* shapes_dest, PointsConfig cfg);

#endif