#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Engine.hpp"
#include "../include/Vec2.hpp"

Engine::Engine() {
    this->gravity = 9.8f;
}

void Engine::render() {
    sf::RenderWindow window(sf::VideoMode{600, 800}, "Physics Engine", sf::Style::Close | sf::Style::Resize);
    window.setFramerateLimit(60);
    sf::Clock clock;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            switch (evnt.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        window.clear(sf::Color::Black);
        window.display();
    }
}

Body Engine::createBody(Vec2 pos, float mass, float radius) {
    bodies.push_back(Body{pos, Vec2{}, mass, radius});
}

Body Engine::createBody(Vec2 pos, float mass, float radius, Vec2 initialVelocity) {
    bodies.push_back(Body{pos, initialVelocity, mass, radius});
}