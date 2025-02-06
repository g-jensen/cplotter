#ifndef _EVENT_MOCK_H_
#define _EVENT_MOCK_H_

#include "../event.h"

enum EventType {
  EventEmpty,
  EventClosed,
  EventMouseMoved
};

struct Event {
  int type;
};

#endif
