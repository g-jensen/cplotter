#define should_vectorf_eq(_expected,_actual)\
  {\
    Vec2f expected = (Vec2f)_expected;\
    Vec2f actual = (Vec2f)_actual;\
    if (!(expected.x == actual.x && expected.y == actual.y)) {\
      specc_fail_message(" | Expected: {%f, %f} Actual: {%f, %f}",expected.x, expected.y, actual.x, actual.y);\
    }\
  }

void should_rect_eq(Rectangle* expected, Rectangle* actual) {
  Vec2f expected_pos = rectangle_pos(expected);
  Vec2f actual_pos = rectangle_pos(actual);
  if (!vector_equals(expected_pos,actual_pos)) {
    specc_fail_message(" | Expected rectangle pos: {%f, %f} Actual: {%f, %f}",expected_pos.x, expected_pos.y, actual_pos.x, actual_pos.y);
  }
  Vec2f expected_size = rectangle_size(expected);
  Vec2f actual_size = rectangle_size(actual);
  if (!vector_equals(expected_pos,actual_pos)) {
    specc_fail_message(" | Expected rectangle size: {%f, %f} Actual: {%f, %f}",expected_size.x, expected_size.y, actual_size.x, actual_size.y);
  }
  float expected_rot = rectangle_rot(expected);
  float actual_rot = rectangle_rot(actual);
  if (!(expected_rot == actual_rot)) {
    specc_fail_message(" | Expected rectangle rotation: %f Actual: %f",expected_rot, actual_rot);
  }
}
