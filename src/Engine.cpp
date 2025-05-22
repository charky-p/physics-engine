#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Engine.hpp"
#include "../include/Vec2.hpp"
#include "../include/Body.hpp"

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
        // Render bodies
        for (Body body : bodies) {
            body.draw(window);
        }
        window.display();
    }
}

void Engine::createBody(Vec2 pos, float mass, float radius) {
    bodies.push_back(Body{pos, Vec2{}, mass, radius});
}

void Engine::createBody(Vec2 pos, float mass, float radius, Vec2 initialVelocity) {
    bodies.push_back(Body{pos, initialVelocity, mass, radius});
}