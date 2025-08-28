#pragma once
#include <string>
 
class GameObject; 
class Component {
    protected:
        GameObject* gameObject;
    public:
        Component(GameObject* obj) : gameObject(obj) {}
        virtual ~Component() {}

        virtual void start() {}
        virtual void update(float deltaTime) {}
};
