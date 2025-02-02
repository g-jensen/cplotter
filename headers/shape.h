#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <stdlib.h>
#include <string.h>

#include "rectangle.h"
#include "circle.h"

enum {
  ShapeRectangle,
  ShapeCircle
};

typedef struct Shape {
  void* data;
  int type;
} Shape;

Shape shape_rectangle(Rectangle* rectangle_shape);
Shape shape_circle(Circle* circle_shape);

Rectangle* shape_as_rect(Shape shape);
Circle* shape_as_circle(Shape shape);

void shape_destroy(Shape shape);

#endif