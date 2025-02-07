#ifndef _WINDOW_MOCK_H_
#define _WINDOW_MOCK_H_

#include "../shape.h"
#include "event_mock.h"

typedef struct ShapeNode ShapeNode;

struct ShapeNode {
  Shape shape;
  ShapeNode* next;
};

typedef struct ShapeList {
  ShapeNode* first;
  ShapeNode* last;
} ShapeList;

typedef struct EventNode EventNode;

struct EventNode {
  Event event;
  EventNode* next;
};

typedef struct EventList {
  EventNode* first;
  EventNode* last;
} EventList;

struct Window {
  int is_open;
  ShapeList drawn_shapes;
  ShapeList displayed_shapes;
  Vec2i mouse_pos;
  EventList events;
};

void add_event(Window* window, Event event);

#endif
