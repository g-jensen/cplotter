#include "../headers/points_config.h"

PointsConfig points_config(size_t num_points, float rect_thickness, float circle_radius) {
  return (PointsConfig){.num_points=num_points, .rect_thickness=rect_thickness, .circle_radius=circle_radius};
}