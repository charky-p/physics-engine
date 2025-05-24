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
    void setGravity(float gravity);
    void setTimeScale(double timeScale);

private:
    // Meta info
    float gravity;
    double timeScale = 1;
    bool doMerge;
    std::vector<Body> bodies;
};