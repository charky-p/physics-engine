#include "../include/Vec2.hpp"

class Body {
  private:
    Vec2 position, velocity, acceleration;
    double mass, radius;

  public:
    Body(Vec2 pos, Vec2 initialVelocity, double m, double r);

    void applyForce(Vec2 Force);

    void update(float deltaTime);

    Vec2 getPosition();
};
