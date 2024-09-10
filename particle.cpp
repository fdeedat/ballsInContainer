#include "particle.h"

particle::particle(float posX, float posY, float velX, float velY,float radius,float mass){
    pos.x = posX;
    pos.y = posY;
    
    vel.x = velX;
    vel.y = velY;

    this->radius = radius;
    this->mass = mass;

    particleShape.setRadius(radius);
    particleShape.setPosition(pos);

    particleShape.setFillColor(sf::Color::White);
}

sf::Vector2f particle::getPos(){
    return pos;
}

sf::Vector2f particle::getVel(){
    return vel;
}

float particle::getRadius(){
    return radius;
}

void particle::updateVel(double vx, double vy, double dt){
    // const float g = 100;
    vel.x = vx;
    vel.y = vy;
}

void particle::gravity(float g, float dt){
    vel.y += g;
    // pos.y += vel.y;
}

void particle::render(sf::RenderWindow &window){
    particleShape.setPosition(pos);
    window.draw(particleShape);
}

void particle::updatePos(float dt){
    // float g = 0.0f;
    // vel.y += g*dt;

    pos += sf::Vector2f(vel.x*dt, vel.y*dt);
    // std::cout<<"nigga"<<std::endl;
}