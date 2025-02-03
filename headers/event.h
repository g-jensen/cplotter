#ifndef _EVENT_H_
#define _EVENT_H_

typedef struct Event Event;

Event* create_event();
void event_destroy(Event* e);

int is_closed_event(Event* event);
int is_mouse_moved_event(Event* event);

#endif
