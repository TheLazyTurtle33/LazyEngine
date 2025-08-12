#ifndef TRANSFORM_H
#define TRANSFORM_H


#include "property.h"
#include "../math/math.h"

namespace property {

// Public inheritance so it’s usable via a base pointer
class Transform2D : public Property {
public:
    Transform2D();
    explicit Transform2D(const LEMath::Vector2& position, const LEMath::Vector2& scale = {1,1}, float rotation = 0);
    // ~Transform2D();

    // void start();
    // void update(int deltaT);
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

    void translate(const LEMath::Vector2& translation);
    void translate(float x, float y);
    void translate(int x, int y);
    void translate(const Transform2D& translation);
    void translate(const Transform2D* translation);

    void rotate(int degrees);
    void rotate(float degrees);
    void rotateR(int radians);
    void rotateR(float radians);

    void Scale(const LEMath::Vector2& scale);
    void Scale(float x, float y);
    void Scale(int x, int y);
    void Scale(float scale);
    void Scale(int scale);

    [[nodiscard]] LEMath::Vector2 getPosition() const;
    [[nodiscard]] LEMath::Vector2 getScale() const;
    [[nodiscard]] float getRotation() const;
    [[nodiscard]] float getRotationR() const;
    [[nodiscard]] LEMath::Vector2 getRight() const;
    [[nodiscard]] LEMath::Vector2 getUp() const;
    [[nodiscard]] LEMath::Vector2 getWorldPosition() const;
    [[nodiscard]] LEMath::Vector2 getWorldScale() const;
    [[nodiscard]] float getWorldRotation() const;
    [[nodiscard]] float getWorldRotationR() const;
    [[nodiscard]] LEMath::Vector2 getWorldForward() const;




    void lookAt(const LEMath::Vector2& target);
    void lookAt(float x, float y);
    void lookAt(int x, int y);
    void lookAt(const Transform2D& target);
    void lookAt(const Transform2D* target);



    LEMath::Vector2 position = {0,0};
    LEMath::Vector2 scale = {1,1};
private:
    float rotation{0};

};


} // namespace property

#endif // TRANSFORM_H