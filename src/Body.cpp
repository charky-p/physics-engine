#include "../include/Vec2.hpp"

class Body {
  private:
    Vec2 position;
    Vec2 velocity;
    Vec2 acceleration;
    double mass;
    double radius;

  public:
    Body(Vec2 pos, Vec2 initialVelocity, double m, double r) {
      position = pos;
      velocity = initialVelocity;
      mass = m;
      radius = r;
    }

    void applyForce(Vec2 force) {
      // Implement proper equation here, account for mass gravity etc.
      acceleration.add(force);
    }

    void update(float deltaTime) {
      Vec2 deltaVelocity = acceleration;
      deltaVelocity.mult(deltaTime);
      velocity.add(deltaVelocity);

      Vec2 displacement = velocity;
      displacement.mult(deltaTime);
      position.add(displacement);

      // Reset acceleration each tick
      acceleration = Vec2();
    }

    Vec2 getPosition() {
      return position;
    }
};
