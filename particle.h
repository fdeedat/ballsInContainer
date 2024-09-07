#pragma once
#include <SFML/Graphics.hpp>

class particle{
    sf::Vector2f pos;
    sf::Vector2f vel;
    float radius;
    sf::CircleShape particleShape;

    public:
    particle(float posX, float posY, float velX, float velY, float radius);
    sf::Vector2f getPos();
    sf::Vector2f getVel();
    void render(sf::RenderWindow &window);
    
    void update(float dt);
};
#include "particle.cpp"

// class tank{
//     sf::
// }