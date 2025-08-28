#pragma once
#include "Scene.h"

class Engine {
    private:
        Scene* currentScene;
        bool isRunning;

    public:
        Engine() : currentScene(nullptr), isRunning(false) {}

        void loadScene(Scene* scene) {
            currentScene = scene;
        }

        void run() {
            isRunning = true;
            if (currentScene) currentScene->start();

            while (isRunning) {
                float deltaTime = 0.016f;
                if (currentScene) currentScene->update(deltaTime);
            }
        }

        void stop() { isRunning = false; }
};
