#pragma once
#include "../Core/Component.h"
#include "../Core/Transform.h"
#include <Arduino.h>
#include <TFT_eSPI.h>

class SpriteRenderer : public Component {
public:
    SpriteRenderer(GameObject* owner, TFT_eSPI* display);

    /* Image */
    void setBitmap(const uint16_t* bmp, int w, int h);

    void setSpriteSheet(const uint16_t* bmp, int frameW, int frameH, int cols, int rows);
    void playAnimation(float fps, bool loop = true);

    void setFrame(int index);
    void update(float dt);
    void render();

private:
    TFT_eSPI* tft;
    const uint16_t* bitmap{nullptr};
    int width{0}, height{0};

    bool animated{false};
    int frameW{0}, frameH{0};
    int cols{0}, rows{0};
    int totalFrames{0};
    int currentFrame{0};
    float fps{0};
    float timeAccum{0};
    bool loop{true};
};
