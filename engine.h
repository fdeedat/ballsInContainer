#pragma once
#include "particle.h"
#include "container.h"

class engine{
    std::vector<particle> particles;

public:    
    void addParticle(particle &p);;
    void updateDynamics(particle &p, float dt,sf::RenderWindow &w,container &c);

private:
    void handleCollisions();
    void resolveCollision(particle& p1, particle& p2);
    void handleWallCollisions(particle& p, container& c);
    float dotProduct(sf::Vector2f v1, sf::Vector2f v2);
};
#include "engine.cpp"