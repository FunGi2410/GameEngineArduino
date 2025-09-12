#pragma once

struct Vector2 {
    float x{0.f};
    float y{0.f};

    Vector2() = default;
    Vector2(float _x, float _y) : x(_x), y(_y) {}

    Vector2 operator+(const Vector2& o) const {  
        return {x + o.x, y + o.y};
    }
    Vector2 operator-(const Vector2& o) const { 
        return {x - o.x, y - o.y}; 
    }
    Vector2 operator*(float s) const { 
        return {x * s, y * s}; 
    }
    Vector2& operator+=(const Vector2& o) { 
        x += o.x; y += o.y; 
        return *this; 
    }
    Vector2& operator-=(const Vector2& o) { 
        x -= o.x; y -= o.y; 
        return *this; 
    }
    Vector2& operator*=(float s) { 
        x *= s; y *= s; 
        return *this; 
    }
};
