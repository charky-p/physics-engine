#pragma once
#include "../include/Vec2.hpp"
#include "SFML/Graphics.hpp"

class Body {
  private:
    Vec2 position, velocity, acceleration;
    double mass, radius;

  public:
    Body(Vec2 pos, Vec2 initialVelocity, double m, double r);

    void applyForce(Vec2 Force);

    void update(float deltaTime);

    void merge(Body& body);

    void draw(sf::RenderWindow& window);

    Vec2 getPosition();

    Vec2 getVelocity();

    double getMass();

    double getRadius();
};
