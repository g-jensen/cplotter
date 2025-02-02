#include "../../headers/circle.h"
#include "../../headers/SFML/sf_circle.h"
#include "../../headers/SFML/sf_vector.h"

#include <stdlib.h>

Circle* circle_create() {
  Circle* c = (Circle*)calloc(1,sizeof(Circle));
  c->sf = sfCircleShape_create();
  return c;
}

void circle_destroy(Circle* circle) {sfCircleShape_destroy(circle->sf); free(circle);}

Vec2f circle_pos(Circle* circle) {return sf_to_vecf(sfCircleShape_getPosition(circle->sf));}
float circle_radius(Circle* circle) {return sfCircleShape_getRadius(circle->sf);}

void circle_set_pos(Circle* circle, Vec2f position) {sfCircleShape_setPosition(circle->sf,vecf_to_sf(position));}
void circle_set_radius(Circle* circle, float radius) {sfCircleShape_setRadius(circle->sf,radius);}