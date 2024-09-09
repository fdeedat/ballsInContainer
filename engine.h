#pragma once
#include "particle.h"
#include "container.h"

class engine{
    std::vector<particle> particles;

public:    
    void addParticle(particle &p);;
    void updateDynamics(float dt,sf::RenderWindow &w,container &c);
    void createParticles(int numParticles, sf::Vector2f positionRange, sf::Vector2f velocityRange, float radius);

private:
    void handleCollisions(float dt);
    void resolveCollision(particle& p1, particle& p2, float dt);
    void handleWallCollisions(particle& p, container& c, float dt);
    float dotProduct(sf::Vector2f v1, sf::Vector2f v2);
    float getRandomFloat(float min, float max);
};
#include "engine.cpp"