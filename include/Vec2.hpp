#pragma once

class Vec2 {
public:
    Vec2();
    Vec2(float x, float y);
    void add(Vec2& other);
    void sub(Vec2& other);
    void mult(float scalar);
    void div(float scalar);
    float dot(Vec2& other);
    float length();
    Vec2 norm();
    float getX();
    float getY();

private:
    float x, y;
};