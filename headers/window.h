#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "event.h"
#include "vector.h"
#include "shape.h"

typedef struct Window Window;

Window* window_create(unsigned int width, unsigned int height);
void window_draw(Window* window, Shape shape);
int window_is_open(Window* window);
void window_close(Window* window);
int window_poll_event(Window* window, Event* event);
Vec2i window_mouse_pos(Window* window);
void window_clear(Window* window);
void window_display(Window* window);
void window_destroy(Window* window);

#endif