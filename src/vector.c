#include "../headers/vector.h"

Vec2f vector_add(Vec2f point1, Vec2f point2) {
  return (Vec2f){point1.x + point2.x, point1.y + point2.y};
}

Vec2f vector_sub(Vec2f point1, Vec2f point2) {
  return (Vec2f){point1.x - point2.x, point1.y - point2.y};
}

Vec2f vector_mult(float scalar, Vec2f point) {
  return (Vec2f){scalar * point.x, scalar * point.y};
}

float vector_distance(Vec2f point1, Vec2f point2) {
  float dx = point2.x - point1.x;
  float dy = point2.y - point1.y;
  return sqrt(dx*dx + dy*dy);
}

int vector_equals(Vec2f point1, Vec2f point2) {
  return point1.x == point2.x && point1.y == point2.y;
}

float vector_magnitude(Vec2f point1) {
  return vector_distance((Vec2f){0,0},point1);
}

Vec2f vector_normalize(Vec2f point1) {
  float m = vector_magnitude(point1);
  if (m == 0.f)
    return point1;
  return (Vec2f){point1.x / m, point1.y / m};
}