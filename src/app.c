#include "../headers/app.h"

// 66,144 bytes in use at exit

int app_run(int argc, char **argv) {
  Window *window = window_create();

  Shape* shapes = (Shape*)malloc(9*sizeof(Shape));
  PointsConfig cfg = points_config(5,2,4);
  Vec2f points[5] = {{10,10},{50,50},{90,90},{100,100},{200,300}};
  points_to_shapes(points,shapes,cfg);

  Vec2f v1 = {400,400};
  Vec2f v2 = {400,600};
  Shape s = shape_rectangle(create_rectangle_between(v1,v2,2));

  Event* event = create_event();
  while (window_is_open(window)) {
    while (window_poll_event(window, event)) {
      if (is_closed_event(event)) {
        window_close(window);
      }
      if (is_mouse_moved_event(event)) {
        shape_destroy(s);
        Vec2i v = window_mouse_pos(window);
        s = shape_rectangle(create_rectangle_between(v1,(Vec2f){v.x,v.y},2));
      }
    }

    window_clear(window);
    window_draw(window, s);
    for (int i = 0; i < 9; i++) {
      window_draw(window,shapes[i]);
    }
    window_display(window);
  }

  shape_destroy(s);
  window_destroy(window);
  event_destroy(event);
  for (int i = 0; i < 9; i++) {
    shape_destroy(shapes[i]);
  }
  free(shapes);

  return 0;
}