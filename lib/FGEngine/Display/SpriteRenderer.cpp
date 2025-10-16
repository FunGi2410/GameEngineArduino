#include "SpriteRenderer.h"
#include "../Core/GameObject.h"

SpriteRenderer::SpriteRenderer(GameObject* owner, TFT_eSPI* display) : Component(owner), tft(display) {}

void SpriteRenderer::setBitmap(const uint16_t* bmp, int w, int h) {
    bitmap = bmp;
    width = w;
    height = h;
    animated = false;
}

void SpriteRenderer::setSpriteSheet(const uint16_t* bmp, int fw, int fh, int c, int r) {
    bitmap = bmp;
    frameW = fw;
    frameH = fh;
    cols = c;
    rows = r;
    totalFrames = c * r;
    animated = true;
}

void SpriteRenderer::playAnimation(float framesPerSec, bool isLoop) {
    fps = framesPerSec;
    loop = isLoop;
    timeAccum = 0;
    currentFrame = 0;
}

void SpriteRenderer::setFrame(int index) {
    if (index >= 0 && index < totalFrames) {
        currentFrame = index;
    }
}

void SpriteRenderer::update(float dt) {
    if (animated && fps > 0) {
        timeAccum += dt;
        if (timeAccum >= 1.0f / fps) {
            timeAccum = 0;
            currentFrame++;
            if (currentFrame >= totalFrames) {
                if (loop) currentFrame = 0;
                else currentFrame = totalFrames - 1;
            }
        }
    }
}

void SpriteRenderer::render() {
    Transform* tf = gameObject->getComponent<Transform>();
    if (!tf || !bitmap) return;

    int x = (int)tf->position.x;
    int y = (int)tf->position.y;

    if (!animated) {
        tft->pushImage(x, y, width, height, bitmap);
    } else {
        int col = currentFrame % cols;
        int row = currentFrame / cols;

        tft->pushImage(x, y, frameW, frameH, bitmap + (row * cols * frameW * frameH) + (col * frameW));
    }
}
