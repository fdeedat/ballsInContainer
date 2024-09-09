#include "engine.h"
#include <cmath>

float engine::dotProduct(sf::Vector2f v1, sf::Vector2f v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

void engine:: resolveCollision(particle& p1, particle& p2) {

    // collision to another particle
    sf::Vector2f delta = p1.getPos() - p2.getPos();
    float dist = sqrt(delta.x * delta.x + delta.y * delta.y);
    float combinedRadius = p1.getRadius() + p2.getRadius();
    
    if (dist <= combinedRadius) {
        sf::Vector2f normal = delta / dist;
        sf::Vector2f relativeVelocity1 = p1.getVel() - p2.getVel();
        sf::Vector2f relativeVelocity2 = -relativeVelocity1;
        float speed1 = dotProduct(relativeVelocity1, normal);
        float speed2 = dotProduct(relativeVelocity2, normal);
        
        if (speed1 > 0) return; // not colliding

        // tumbukan diasumsikan lenting sempurna or someshit

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

void engine::handleWallCollisions(particle &p, container &c){
    /*
    * - detects if particle collides with wall
    *   - select 
    * - p.vel = -curr p.vel
    */
   sf::Vector2f bottomWall = c.getBottomWallPos();
   sf::Vector2f leftWall = c.getLeftWallPos();
   sf::Vector2f rightWall = c.getRightWallPos();

   float particlePosX = p.getPos().x;
   float particlePosY = p.getPos().y;

    if(particlePosY + p.getRadius() > leftWall.y && particlePosX + p.getRadius() <= leftWall.x){
        p.updateVel(-p.getVel().x,p.getVel().y);
    } else if(particlePosY + p.getRadius() > bottomWall.y) {
        p.updateVel(p.getVel().x,-p.getVel().y);
    } else if(particlePosY + p.getRadius() > rightWall.y && particlePosX + p.getRadius() > rightWall.x){
        p.updateVel(-p.getVel().x,p.getVel().y);
    };
}

void engine::updateDynamics(particle &p, float dt, sf::RenderWindow &w, container &c){
    for (auto& particle : particles) {
        particle.updatePos(dt);
        particle.render(w);
        handleWallCollisions(particle,c);
    }
    handleCollisions();
}
