#include "../../headers/rectangle.h"
#include "../../headers/SFML/sf_rectangle.h"
#include "../../headers/SFML/sf_vector.h"

#include <stdlib.h>

Rectangle* rectangle_create() {
  Rectangle* r = (Rectangle*)calloc(1,sizeof(Rectangle));
  r->sf = sfRectangleShape_create();
  return r;
}

void rectangle_destroy(Rectangle* rectangle) {sfRectangleShape_destroy(rectangle->sf); free(rectangle);}

Vec2f rectangle_pos(Rectangle* rectangle) {return sf_to_vecf(sfRectangleShape_getPosition(rectangle->sf));}
Vec2f rectangle_size(Rectangle* rectangle) {return sf_to_vecf(sfRectangleShape_getSize(rectangle->sf));}
float rectangle_rot(Rectangle* rectangle) {return sfRectangleShape_getRotation(rectangle->sf);}

void rectangle_set_pos(Rectangle* rectangle, Vec2f position) {sfRectangleShape_setPosition(rectangle->sf,vecf_to_sf(position));}
void rectangle_set_size(Rectangle* rectangle, Vec2f size) {sfRectangleShape_setSize(rectangle->sf,vecf_to_sf(size));}
void rectangle_set_rot(Rectangle* rectangle, float rotation) {sfRectangleShape_setRotation(rectangle->sf,rotation);}