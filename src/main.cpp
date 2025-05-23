#include <iostream>
#include <cmath>
#include "../include/Engine.hpp"

int main() {
    Engine engine;
    // Vec2 pos1(100, 100);
    // Vec2 pos2(400, 200);
    // Vec2 pos3(100, 400);
    // // engine.createBody(pos1, 5.972e15, 50);
    // // engine.createBody(pos2, 7.342e15, 80);
    // // engine.createBody(pos3, 1e15, 20);
    // // Vec2 vel1(180, 30);
    // // Vec2 vel2(300, 60);
    // // engine.createBody(pos1, 5e15, 50, vel1);
    // // // engine.createBody(pos2, 1e15, 80);
    // // engine.createBody(pos3, 5e16, 20, vel2);
    // Vec2 pos4(600, 600);
    // Vec2 vel1(150, 0);
    // Vec2 vel2(-100, 0);
    // engine.createBody(pos1, 5e17, 50, vel1);
    // engine.createBody(pos4, 5e17, 30, vel2);
    // // engine.createBody(pos2, 5e17, 30);

    // 2 bodies orbitting, eventually irradicate
    // Vec2 pos1(100, 100);
    // Vec2 pos2(600, 600);
    // Vec2 vel1(150, 0);
    // Vec2 vel2(-100, 0);
    // engine.createBody(pos1, 5e17, 50, vel1);
    // engine.createBody(pos2, 5e17, 30, vel2);

    // 3 bodies that irradicate
    float R = 600;
    double mass = 1e18;
    double G = 6.67430e-11;
    double v = sqrt(G * 2 * mass / R);

    Vec2 pos1(R, 0);
    Vec2 pos2(-R/2, R * sqrt(3)/2);
    Vec2 pos3(-R/2, -R * sqrt(3)/2);

    // Unit vectors perpendicular to each radius (CCW)
    Vec2 vel1(0, v);
    Vec2 vel2(-sqrt(3)/2, -50);
    Vec2 vel3(v * sqrt(3)/2, -v/2);

    engine.createBody(pos1, mass, 150, vel1);
    engine.createBody(pos2, mass * 10, 80, vel2);
    engine.createBody(pos3, mass, 50, vel3);
    engine.render();
    return 0;
}