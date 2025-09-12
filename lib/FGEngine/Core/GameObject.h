#pragma once
#include <vector>
#include <string>
#include <memory>
#include <type_traits>
#include "Component.h"
#include "Transform.h"

class GameObject {
    private:
        std::string name;
        std::vector<std::unique_ptr<Component>> components;

    public:
        Transform* transform{nullptr}; 

        explicit GameObject(const std::string& n) : name(n) {
            transform = addComponent<Transform>();
        }

        template<typename T, typename... Args>
        T* addComponent(Args&&... args) {
            static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
            T* comp = new T(this, std::forward<Args>(args)...);
            components.emplace_back(comp);
            return comp;
        }

        template<typename T>
        T* getComponent() {
            static_assert(std::is_base_of<Component, T>::value,
                        "T must derive from Component");
            for (auto& c : components) {
                if (auto p = dynamic_cast<T*>(c.get())) return p;
            }
            return nullptr;
        }

        void start() {
            for (auto& comp : components) comp->start();
        }

        void update(float deltaTime) {
            for (auto& comp : components) comp->update(deltaTime);
        }

        const std::string& getName() const { return name; }
};
