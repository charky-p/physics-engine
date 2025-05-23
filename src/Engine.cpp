#include <iostream>
#include <set>
#include <SFML/Graphics.hpp>
#include "../include/Engine.hpp"
#include "../include/Vec2.hpp"
#include "../include/Body.hpp"

Engine::Engine() {
    this->gravity = 6.67430e-11;
    // Do merge by default
    this->doMerge = true;
}

void Engine::render() {
    sf::RenderWindow window(sf::VideoMode{800, 600}, "Physics Engine", sf::Style::Close | sf::Style::Resize);
    window.setPosition(sf::Vector2i(100, 100));
    window.setFramerateLimit(60);
    sf::Clock clock;

    sf::View view(sf::FloatRect(0, 0, 800, 600));
    view.zoom(2.0f);

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            switch (evnt.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    view.setSize(evnt.size.width, evnt.size.height);
                    break;
                case sf::Event::KeyPressed:
                    if (evnt.key.code == sf::Keyboard::Add || evnt.key.code == sf::Keyboard::Equal) {
                        // Zoom in
                        view.zoom(0.5f);
                    } else if (evnt.key.code == sf::Keyboard::Subtract || evnt.key.code == sf::Keyboard::Hyphen) {
                        // Zoom out
                        view.zoom(2.0f);
                    }
                    break;
            }
        }

        // Tick
        tick(dt);

        // Set view to be the centroid of all the bodies
        if (!bodies.empty()) {
            Vec2 centroid(0.f, 0.f);
            for (Body& body : bodies) {
                centroid.add(body.getPosition());
            }
            centroid.div(bodies.size());
            view.setCenter(sf::Vector2f{centroid.getX(), centroid.getY()});
        }

        window.setView(view);
        window.clear(sf::Color::Black);
        // Render bodies
        for (Body& body : bodies) {
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

void Engine::tick(int ticks, float dt) {
    for (int i = 0; i < ticks; i++) {
        tick(dt);
    }
}

void Engine::tick(float dt) {
    std::vector<std::pair<int, int>> merging;

    // Compute gravitional pulls for all bodies
    for (int i = 0; i < bodies.size(); i++) {
        Body& body1 = bodies[i];
        for (int j = i + 1; j < bodies.size(); j++) {
            Body& body2 = bodies[j];
            Vec2 distance = body2.getPosition();
            distance.sub(body1.getPosition());

            // Collision detection
            if (distance.length() < body1.getRadius() + body2.getRadius()) {
                merging.push_back({i, j});
                continue;
            }
            
            float length = std::max(5, (int) distance.length());
            double force = gravity * body1.getMass() * body2.getMass();
            force /= length * length;

            Vec2 unit = Vec2{distance.getX() / length, distance.getY() / length};
            unit.mult(force);
            body1.applyForce(unit);
            unit.mult(-1);
            body2.applyForce(unit);
        }
    }

    // Merging
    if (doMerge) {
        std::set<int> alreadyMerged;
        for (auto& pair : merging) {
            int i = pair.first;
            int j = pair.second;
            if (alreadyMerged.count(i) || alreadyMerged.count(j)) {
                continue;
            }

            bodies[i].merge(bodies[j]);
            bodies.erase(bodies.begin() + j);

            alreadyMerged.insert(i);
            alreadyMerged.insert(j);
        }
    }

    // Move bodies based off velocity
    for (Body& body : bodies) {
        body.update(dt);
    }
}