#include "particle.h"

particle::particle(float posX, float posY, float velX, float velY,float radius){
    pos.x = posX;
    pos.y = posY;
    
    vel.x = velX;
    vel.y = velY;

    this->radius = radius;

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

void particle::render(sf::RenderWindow &window){
    particleShape.setPosition(pos);
    window.draw(particleShape);
}

void particle::update(float dt){
    
    /* F = m a
    *  m g = m a
    *  a = -g
    */
   float ax, ay;
   if(pos.y+this->radius>750.0f) vel.y = -std::abs(vel.y);

   ay = 9.81f*20; // 1 pixel = 20 m
   vel.y += ay*dt;
   pos.y += vel.y*dt;

   vel.x += ax*dt*20;
   pos.x += vel.x*dt;
}