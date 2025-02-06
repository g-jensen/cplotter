#ifdef SPECC

#include "../../headers/mocks/event_mock.h"

#include <stdlib.h>

Event* create_event() {
  Event* event = malloc(sizeof(Event));
  *event = (Event){.type=EventEmpty};
  return event;
}

void event_destroy(Event* e) {
  free(e);
}

int is_closed_event(Event* event) {
  return event->type == EventClosed;
}

int is_mouse_moved_event(Event* event) {
  return event->type == EventMouseMoved;
}

#endif