#include "../headers/render.h"

Rectangle* create_rectangle_between(Vec2f point1, Vec2f point2, float thickness) {
  float dx = point2.x - point1.x;
  float dy = point2.y - point1.y; 
  Vec2f adjust = vector_mult(thickness / 2, vector_normalize((Vec2f){-dy,dx}));
  Rectangle* r = rectangle_create();
  int sgn = dx < 0 ? -1 : 1;
  rectangle_set_pos(r,vector_sub(point1,adjust));
  rectangle_set_size(r,(Vec2f){sgn*vector_distance(point1,point2),sgn*thickness});
  if (vector_equals(point1,point2)) return r;
  rectangle_set_rot(r,180/M_PI*atan(dy/dx));
  return r;
}

Circle* create_centered_circle(Vec2f center, float radius) {
  Circle* c = circle_create();
  circle_set_radius(c,radius);
  circle_set_pos(c,(Vec2f){center.x-radius,center.y-radius});
  return c;
}

void points_to_shapes(Vec2f* points, Shape* shapes_dest, PointsConfig cfg) {
  if (cfg.num_points < 1) return;

  size_t i = 0;
  float r = cfg.circle_radius;
  float t = cfg.rect_thickness;
  
  shapes_dest[i++] = shape_circle(create_centered_circle(points[0],r));
  for (size_t p = 1; p < cfg.num_points; p++) {
    Vec2f prev = points[p-1];
    Vec2f current = points[p];
    shapes_dest[i++] = shape_rectangle(create_rectangle_between(prev,current,t));
    shapes_dest[i++] = shape_circle(create_centered_circle(current,r));
  }
}