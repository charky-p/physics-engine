#pragma once
#include "Body.hpp"
#include <vector>

class Engine {
public:
    Engine();
    void render();
    void createBody(Vec2 pos, float mass, float radius);
    void createBody(Vec2 pos, float mass, float radius, Vec2 initialVelocity);
    void tick(int ticks, float dt);
    void tick(float dt);

private:
    // Meta info
    float gravity;
    std::vector<Body> bodies;
};