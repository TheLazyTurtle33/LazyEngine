#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../Engine.h"
#include "property.h"
#include "../math/math.h"

namespace property {

// Public inheritance so it’s usable via a base pointer
class Transform2D : public Property {
public:
    Transform2D();
    ~Transform2D() override;

    void start() override;
    void update(int deltaT) override;
    void destroy() override;

    void setPosition(const LEMath::Vector2& position);
    void setPosition(float x, float y);
    void setPosition(int x, int y);
    void setScale(const LEMath::Vector2& scale);
    void setScale(float x, float y);
    void setScale(int x, int y);
    void setScale(float scale);
    void setScale(int scale);
    void setRotation(int degrees);
    void setRotation(float degrees);
    void setRotationR(int radians);
    void setRotationR(float radians);


    void lookAt(const LEMath::Vector2& target);
    void lookAt(float x, float y);
    void lookAt(int x, int y);
    void lookAt(const Transform2D& target);
    void lookAt(const Transform2D* target);



    LEMath::Vector2 position = {0,0};
    LEMath::Vector2 scale = {1,1};
    float rotation{0};

private:

};


} // namespace property

#endif // TRANSFORM_H