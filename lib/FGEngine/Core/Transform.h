#pragma once
#include "Component.h"
#include "Vector2.h"

class Transform : public Component {
    public:
        Vector2 position{0.f, 0.f};
        float   rotation{0.f};      
        Vector2 scale{1.f, 1.f};

        explicit Transform(GameObject* owner)
            : Component(owner) {}

        void translate(const Vector2& delta) { position += delta; }
        void setPosition(float x, float y)    { position.x = x; position.y = y; }
        void setRotation(float deg)           { rotation = deg; }
        void setScale(float sx, float sy)     { scale.x = sx; scale.y = sy; }
};
