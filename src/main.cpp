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
    // float R = 600;
    // double mass = 1e18;
    // double G = 6.67430e-11;
    // double v = sqrt(G * 2 * mass / R);

    // Vec2 pos1(R, 0);
    // Vec2 pos2(-R/2, R * sqrt(3)/2);
    // Vec2 pos3(-R/2, -R * sqrt(3)/2);

    // // Unit vectors perpendicular to each radius (CCW)
    // Vec2 vel1(0, v);
    // Vec2 vel2(-sqrt(3)/2, -50);
    // Vec2 vel3(v * sqrt(3)/2, -v/2);

    // engine.createBody(pos1, mass, 150, vel1);
    // engine.createBody(pos2, mass * 10, 80, vel2);
    // engine.createBody(pos3, mass, 50, vel3);

    // --- SCALE FACTORS ---
    const double massScale = 1e12;        // 1 unit = 1e27 kg
    const double distanceScale = 1e6;     // 1 unit = 1 million km (in km)
    const double timeScale = 1e3;       // 1 unit = 1e3 millisecond

    // Gravitational constant (scaled)
    engine.setGravity(6.67430e-11 * 1e-12 * timeScale);
    engine.setTimeScale(timeScale);

    // --- SUN ---
    Vec2 sunPos(500, 500);
    double sunMass = 1.989e30 / massScale;
    engine.createBody(sunPos, sunMass, 40, Vec2(0, 0));

    // --- Helper for orbital velocity ---
    auto orbitalVelocity = [](double centralMass, double r) {
        double G = 6.67430e-11 * 1e-12 * 1e3;
        return std::sqrt(G * centralMass / r);
    };

    // --- MERCURY ---
    double mercuryDistReal = 57.9e6; // km
    double mercuryMassReal = 3.3e23;
    double mercuryDist = mercuryDistReal / distanceScale;
    double mercuryMass = mercuryMassReal / massScale;
    double mercuryVel = orbitalVelocity(sunMass, mercuryDist);
    engine.createBody(Vec2(sunPos.getX(), sunPos.getY() - mercuryDist), mercuryMass, 5, Vec2(mercuryVel, 0));

    // --- VENUS ---
    double venusDistReal = 108.2e6;
    double venusMassReal = 4.87e24;
    double venusDist = venusDistReal / distanceScale;
    double venusMass = venusMassReal / massScale;
    double venusVel = orbitalVelocity(sunMass, venusDist);
    engine.createBody(Vec2(sunPos.getX(), sunPos.getY() - venusDist), venusMass, 10, Vec2(venusVel, 0));

    // --- EARTH ---
    double earthDistReal = 149.6e6;
    double earthMassReal = 5.97e24;
    double earthDist = earthDistReal / distanceScale;
    double earthMass = earthMassReal / massScale;
    double earthVel = orbitalVelocity(sunMass, earthDist);
    engine.createBody(Vec2(sunPos.getX(), sunPos.getY() - earthDist), earthMass, 12, Vec2(earthVel, 0));

    // --- MARS ---
    double marsDistReal = 227.9e6;
    double marsMassReal = 6.42e23;
    double marsDist = marsDistReal / distanceScale;
    double marsMass = marsMassReal / massScale;
    double marsVel = orbitalVelocity(sunMass, marsDist);
    engine.createBody(Vec2(sunPos.getX(), sunPos.getY() - marsDist), marsMass, 9, Vec2(marsVel, 0));

    if (false) {
        // --- JUPITER ---
        double jupiterDistReal = 778.5e6; // km
        double jupiterMassReal = 1.898e27;
        double jupiterDist = jupiterDistReal / distanceScale;
        double jupiterMass = jupiterMassReal / massScale;
        double jupiterVel = orbitalVelocity(sunMass, jupiterDist);
        engine.createBody(Vec2(sunPos.getX(), sunPos.getY() - jupiterDist), jupiterMass, 15, Vec2(jupiterVel, 0));

        // --- SATURN ---
        double saturnDistReal = 1.429e9; // km
        double saturnMassReal = 5.683e26;
        double saturnDist = saturnDistReal / distanceScale;
        double saturnMass = saturnMassReal / massScale;
        double saturnVel = orbitalVelocity(sunMass, saturnDist);
        engine.createBody(Vec2(sunPos.getX(), sunPos.getY() + saturnDist), saturnMass, 13, Vec2(saturnVel, 0));

        // --- URANUS ---
        double uranusDistReal = 2.871e9; // km
        double uranusMassReal = 8.681e25;
        double uranusDist = uranusDistReal / distanceScale;
        double uranusMass = uranusMassReal / massScale;
        double uranusVel = orbitalVelocity(sunMass, uranusDist);
        engine.createBody(Vec2(sunPos.getX(), sunPos.getY() - uranusDist), uranusMass, 9, Vec2(uranusVel, 0));

        // --- NEPTUNE ---
        double neptuneDistReal = 4.495e9; // km
        double neptuneMassReal = 1.024e26;
        double neptuneDist = neptuneDistReal / distanceScale;
        double neptuneMass = neptuneMassReal / massScale;
        double neptuneVel = orbitalVelocity(sunMass, neptuneDist);
        engine.createBody(Vec2(sunPos.getX(), sunPos.getY() + neptuneDist), neptuneMass, 11, Vec2(neptuneVel, 0));

        // // --- PLUTO ---
        // double plutoDistReal = 5.906e9; // km
        // double plutoMassReal = 1.303e22;
        // double plutoDist = plutoDistReal / distanceScale;
        // double plutoMass = plutoMassReal / massScale;
        // double plutoVel = orbitalVelocity(sunMass, plutoDist);
        // engine.createBody(Vec2(sunPos.getX(), sunPos.getY() + plutoDist), plutoMass, 5, Vec2(plutoVel, 0));
    }
    
    engine.render();
    return 0;
}