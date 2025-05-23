#include "../include/Vec2.hpp"
#include "../include/Body.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

Body::Body(Vec2 position, Vec2 initialVelocity, double mass, double radius) {
    this->position = position;
    this->velocity = initialVelocity;
    this->mass = mass;
    this->radius = radius;
}

void Body::applyForce(Vec2 force) {
    // Implement proper equation here, account for mass gravity etc.
    Vec2 acceleration = force;
    acceleration.div(mass);
    this->acceleration.add(acceleration);
}

void Body::update(float deltaTime) {
    Vec2 deltaVelocity = acceleration;
    deltaVelocity.mult(deltaTime);
    velocity.add(deltaVelocity);

    Vec2 displacement = velocity;
    displacement.mult(deltaTime);
    position.add(displacement);

    // Reset acceleration each tick
    acceleration = Vec2();
}

void Body::draw(sf::RenderWindow& window) {
    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::White);
    circle.setPosition(position.getX() - radius, position.getY() - radius);
    window.draw(circle);
}

Vec2 Body::getPosition() {
    return Vec2{position.getX(), position.getY()};
}

double Body::getMass() {
    return mass;
}

double Body::getRadius() {
    return radius;
}