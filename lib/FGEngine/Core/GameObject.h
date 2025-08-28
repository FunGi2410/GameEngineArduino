#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Component.h"

class GameObject {
    private:
        std::string name;
        std::vector<std::unique_ptr<Component>> components;

    public:
        GameObject(const std::string& n) : name(n) {}

        template<typename T, typename... Args>
        T* addComponent(Args&&... args) {
            T* comp = new T(this, std::forward<Args>(args)...);
            components.emplace_back(comp);
            return comp;
        }

        void start() {
            for (auto& comp : components) comp->start();  
        }

        void update(float deltaTime) {
            for (auto& comp : components) comp->update(deltaTime);
        }

        const std::string& getName() const { return name; }
};
