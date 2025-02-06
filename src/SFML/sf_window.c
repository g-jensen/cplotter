#ifndef SPECC

#include "../../headers/window.h"
#include "../../headers/SFML/sf_window.h"
#include "../../headers/SFML/sf_rectangle.h"
#include "../../headers/SFML/sf_circle.h"
#include "../../headers/SFML/sf_vector.h"
#include "../../headers/SFML/sf_event.h"

#include <stdlib.h>

Window* window_create() {
  sfVideoMode mode = {800, 800, 32};
  Window* w = (Window*)calloc(1,sizeof(Window));
  w->sf = sfRenderWindow_create(mode, "cplotter", sfResize | sfClose, NULL);
  return w;
}

void window_draw(Window* window, Shape shape) {
  switch (shape.type)
  {
  case ShapeRectangle:
    sfRenderWindow_drawRectangleShape(window->sf,shape_as_rect(shape)->sf,NULL);
    break;
  case ShapeCircle:
    sfRenderWindow_drawCircleShape(window->sf,shape_as_circle(shape)->sf,NULL);
  break;
  default:
    break;
  }
}

int window_is_open(Window* window) {return sfRenderWindow_isOpen(window->sf);}
void window_close(Window* window) {sfRenderWindow_close(window->sf);}
int window_poll_event(Window* window, Event* event) {return sfRenderWindow_pollEvent(window->sf,&(event->sf));}
Vec2i window_mouse_pos(Window* window) {return sf_to_veci(sfMouse_getPositionRenderWindow(window->sf));}
void window_clear(Window* window) {sfRenderWindow_clear(window->sf, sfBlack);}
void window_display(Window* window) {sfRenderWindow_display(window->sf);}
void window_destroy(Window* window) {sfRenderWindow_destroy(window->sf); free(window);}

#endif