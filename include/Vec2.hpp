#pragma once

class Vec2 {
public:
    Vec2();
    Vec2(float x, float y);
    void add(const Vec2& other);
    void sub(const Vec2& other);
    void mult(float scalar);
    void div(float scalar);
    float dot(const Vec2& other);
    float length();
    Vec2 norm();
    float getX() const;
    float getY() const;

private:
    float x, y;
};