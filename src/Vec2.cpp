#include <iostream>
#include <cmath>
#include "../include/Vec2.hpp"

Vec2::Vec2() {
    x = 0;
    y = 0;
}

Vec2::Vec2(float x, float y) {
    this->x = x;
    this->y = y;
}

void Vec2::add(Vec2& other) {
    x += other.getX();
    y += other.getY();
}

void Vec2::sub(Vec2& other) {
    x -= other.getX();
    y -= other.getY();
}

void Vec2::mult(float scalar) {
    x *= scalar;
    y *= scalar;
}

void Vec2::div(float scalar) {
    if (scalar == 0) {
        return;
    }
    x /= scalar;
    y /= scalar;
}

float Vec2::dot(Vec2& other) {
    return x * other.getX() + y * other.getY();
}

float Vec2::length() {
    return std::sqrt(x * x + y * y);
}

Vec2 Vec2::norm() {
    float len = length();
    if (len > 0) {
        return Vec2(x / len, y / len);
    }
    return Vec2();
}

float Vec2::getX() {
    return x;
}

float Vec2::getY() {
    return y;
}