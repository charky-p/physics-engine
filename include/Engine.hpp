#pragma once
#include "Body.hpp"
#include <vector>

class Engine {
public:
    Engine();
    void render();
    Body createBody(Vec2 pos, float mass, float radius);
    Body createBody(Vec2 pos, float mass, float radius, Vec2 initialVelocity);

private:
    // Meta info
    float gravity;
    std::vector<Body> bodies;
};