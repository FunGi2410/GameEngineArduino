#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"

class Scene {
    private:
        std::vector<std::unique_ptr<GameObject>> objects;
    public:
        Scene() {}

        GameObject* createObject(const std::string& name) {
            GameObject* obj = new GameObject(name);
            objects.emplace_back(obj);
            return obj;
        }

        void start() {
            for (auto& obj : objects) obj->start();
        }

        void update(float deltaTime) {
            for (auto& obj : objects) obj->update(deltaTime);
        }
};
