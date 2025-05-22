#include <iostream>
#include "../include/Engine.hpp"

int main() {
    Engine engine;
    Vec2 pos1(100, 100);
    Vec2 pos2(400, 200);
    Vec2 pos3(100, 400);
    engine.createBody(pos1, 100, 50);
    engine.createBody(pos2, 400, 80);
    engine.createBody(pos3, 100, 20);
    engine.render();
    return 0;
}