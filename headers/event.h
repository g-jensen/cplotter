#ifndef _EVENT_H_
#define _EVENT_H_

typedef struct Event Event;

Event* create_event();
void event_destroy(Event* e);

int isClosedEvent(Event* event);
int isMouseMovedEvent(Event* event);

#endif
