#pragma once
#include <string>

class GameObject; 

class Component {
    protected:
        GameObject* gameObject{nullptr};
    public:
        explicit Component(GameObject* owner) : gameObject(owner) {}
        virtual ~Component() {}

        virtual void start() {}
        virtual void update(float deltaTime) {}

        GameObject* getGameObject() const { return gameObject; }
};
