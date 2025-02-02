#ifndef _SF_VECTOR_H_
#define _SF_VECTOR_H_

#include "../vector.h"
#include <SFML/System/Vector2.h>

sfVector2f vecf_to_sf(Vec2f vec);
sfVector2i veci_to_sf(Vec2i vec);

Vec2f sf_to_vecf(sfVector2f vec);
Vec2i sf_to_veci(sfVector2i vec);

#endif
