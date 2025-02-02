#include "../../headers/event.h"
#include "../../headers/SFML/sf_event.h"

#include <stdlib.h>
#include <string.h>

Event* create_event() {
  Event* e = calloc(1,sizeof(sfEvent));
  sfEvent sfe;
  e->sf = sfe;
  return e;
}

void event_destroy(Event* e) {
  free(e);
}

int isClosedEvent(Event* event) {
  return event->sf.type == sfEvtClosed;
}

int isMouseMovedEvent(Event* event) {
  return event->sf.type == sfEvtMouseMoved;
}