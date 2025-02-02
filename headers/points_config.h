#ifndef _POINTS_CONFIG_H_
#define _POINTS_CONFIG_H_

#include <stdlib.h>

typedef struct PointsConfig {
  size_t num_points;
  float rect_thickness;
  float circle_radius;
} PointsConfig;

PointsConfig points_config(size_t num_points, float rect_thickness, float circle_radius);

#endif