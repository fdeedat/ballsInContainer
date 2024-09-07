#include "engine.h"
#include <cmath>

float engine::dotProduct(sf::Vector2f v1, sf::Vector2f v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

void engine:: resolveCollision(particle& p1, particle& p2) {
    sf::Vector2f delta = p1.getPos() - p2.getPos();
    float dist = sqrt(delta.x * delta.x + delta.y * delta.y);
    float combinedRadius = p1.getRadius() + p2.getRadius();
    
    if (dist <= combinedRadius) {
        sf::Vector2f normal = delta / dist;
        sf::Vector2f relativeVelocity1 = p1.getVel() - p2.getVel();
        sf::Vector2f relativeVelocity2 = -relativeVelocity1;
        float speed1 = dotProduct(relativeVelocity1, normal);
        float speed2 = dotProduct(relativeVelocity2, normal);
        
        if (speed1 > 0) return; // not 

        float impulse1 = (2.0f * speed1) / (p1.mass + p2.mass);
        float impulse2 = (2.0f * speed2) / (p1.mass + p2.mass);
        
        sf::Vector2f impulseP1 = impulse1 * p2.mass * normal;
        sf::Vector2f impulseP2 = impulse2 * p1.mass * normal;

        sf::Vector2f newVel1 = p1.getVel() - impulseP1; 
        sf::Vector2f newVel2 = p2.getVel() - impulseP2; 
        
        p1.updateVel(newVel1.x,newVel1.y);
        p2.updateVel(newVel2.x,newVel2.y);
    }
}

void engine:: handleCollisions() {
    for (size_t i = 0; i < particles.size(); ++i) {
        for (size_t j = i + 1; j < particles.size(); ++j) {
            resolveCollision(particles[i], particles[j]);
        }
    }
}

void engine::addParticle(particle &p){
    particles.push_back(p);
}

void engine::updateDynamics(particle &p, float dt, sf::RenderWindow &w){
    for (auto& particle : particles) {
        particle.updatePos(dt);
        particle.render(w);
    }
    handleCollisions();
}
