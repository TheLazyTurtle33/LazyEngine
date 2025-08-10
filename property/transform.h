#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "property.h"
#include "../math/math.h"

namespace property {

// Public inheritance so it’s usable via a base pointer
class Transform2D final : public Property {
public:
    LEMath::Vector2 position;
    LEMath::Vector2 scale;
    float rotation;
};


} // namespace property

#endif // TRANSFORM_H