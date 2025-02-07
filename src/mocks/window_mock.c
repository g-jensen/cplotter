#ifdef SPECC

#include "../../headers/window.h"
#include "../../headers/mocks/window_mock.h"

#include <stdlib.h>

EventList empty_event_list() {
  return (EventList){.first=NULL,.last=NULL};
}

EventList empty_event(EventNode* first) {
  return (EventList){.first=first,.last=NULL};
}

EventNode event_node(Event event) {
  return (EventNode){.event=event,.next=NULL};
}

ShapeList empty_shape_list() {
  return (ShapeList){.first=NULL,.last=NULL};
}

ShapeList shape_list(ShapeNode* first) {
  return (ShapeList){.first=first,.last=NULL};
}

ShapeNode shape_node(Shape shape) {
  return (ShapeNode){.shape=shape,.next=NULL};
}

Window* window_create(unsigned int width, unsigned int height) {
  Window* w = malloc(sizeof(Window));
  *w = (Window){
    .is_open=0,
    .mouse_pos={0,0},
    .events=empty_event_list(),
    .drawn_shapes=empty_shape_list()
    };
}

void window_draw(Window* window, Shape shape) {
  ShapeNode* sn = malloc(sizeof(ShapeNode));
  *sn = shape_node(shape);
  window->drawn_shapes.last->next = sn;
  window->drawn_shapes.last = sn;
}

int window_is_open(Window* window) {
  return window->is_open;
}

void window_close(Window* window) {
  window->is_open = 0;
}

int window_poll_event(Window* window, Event* event) {
  *event = window->events.first->event;
  EventNode* next = window->events.first->next;
  free(window->events.first);
  window->events.first = next;
  return event->type;
}

Vec2i window_mouse_pos(Window* window) {
  return window->mouse_pos;
}

void destroy_events(EventList events_list) {
  EventNode* n = events_list.first;
  while (n) {
    EventNode* next = n->next;
    free(n);
    n = next;
  }
}

void destroy_shapes(ShapeList shapes_list) {
  ShapeNode* n = shapes_list.first;
  while (n) {
    ShapeNode* next = n->next;
    free(n);
    n = next;
  }
}

void window_clear(Window* window) {
  destroy_shapes(window->drawn_shapes);
  window->drawn_shapes = empty_shape_list();
}

void window_display(Window* window) {
  window->displayed_shapes = window->drawn_shapes;
  window->drawn_shapes = empty_shape_list();
  if (!window->events.first) {
    window_close(window);
  }
}

void window_destroy(Window* window) {
  destroy_events(window->events);
  destroy_shapes(window->drawn_shapes);
  free(window);
}

void add_event(Window* window, Event event) {
  EventNode* en = malloc(sizeof(EventNode));
  *en = event_node(event);
  if (!window->events.first) {
    window->events.first = en;
    window->events.last = en;
  } else {
    window->events.last->next = en;
    window->events.last = en;
  }
}

#endif