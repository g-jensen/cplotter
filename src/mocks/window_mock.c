#ifdef SPECC

#include "../../headers/window.h"
#include "../../headers/mocks/window_mock.h"

#include <stdlib.h>

Window* window_create() {
  Window* w = malloc(sizeof(Window));
  EventNode* event = malloc(sizeof(EventNode));
  *event = (EventNode){.event=EventEmpty,.next=NULL};
  *w = (Window){
    .is_open=0,
    .mouse_pos={0,0},
    .events={.first=event,.last=event},
    .shapes={.first=NULL,.last=NULL}
    };
}

void window_draw(Window* window, Shape shape) {
  ShapeNode* sn = malloc(sizeof(ShapeNode));
  *sn = (ShapeNode){.shape=shape,.next=NULL};
  window->shapes.last->next = sn;
  window->shapes.last = sn;
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
  destroy_shapes(window->shapes);
  window->shapes = (ShapeList){.first=NULL,.last=NULL};
}

void window_display(Window* window) {
  if (!window->events.first) {
    window_close(window);
  }
}

void window_destroy(Window* window) {
  destroy_events(window->events);
  destroy_shapes(window->shapes);
  free(window);
}

void add_event(Window* window, Event event) {
  EventNode* en = malloc(sizeof(EventNode));
  *en = (EventNode){.event=event,.next=NULL};
  window->events.last->next = en;
  window->events.last = en;
}

#endif