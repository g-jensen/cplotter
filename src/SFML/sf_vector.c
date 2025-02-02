#include "../../headers/SFML/sf_vector.h"

sfVector2f vecf_to_sf(Vec2f vec) {
  return (sfVector2f){vec.x,vec.y};
}

sfVector2i veci_to_sf(Vec2i vec) {
  return (sfVector2i){vec.x,vec.y};
}

Vec2f sf_to_vecf(sfVector2f vec) {
  return (Vec2f){vec.x,vec.y};
}

Vec2i sf_to_veci(sfVector2i vec) {
  return (Vec2i){vec.x,vec.y};
}