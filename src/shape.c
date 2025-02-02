#include "../headers/shape.h"

Shape shape_rectangle(Rectangle* rectangle_shape) {
  return (Shape){.data=rectangle_shape,.type=ShapeRectangle};
}

Shape shape_circle(Circle* circle_shape) {
  return (Shape){.data=circle_shape,.type=ShapeCircle};
}

Rectangle* shape_as_rect(Shape shape) {
  return (Rectangle*)shape.data;
}

Circle* shape_as_circle(Shape shape) {
  return (Circle*)shape.data;
}

void shape_destroy(Shape shape) {
  switch (shape.type)
  {
  case ShapeRectangle:
    rectangle_destroy(shape_as_rect(shape));
    break;
  case ShapeCircle:
    circle_destroy(shape_as_circle(shape));
    break;
  default:
    break;
  }
}