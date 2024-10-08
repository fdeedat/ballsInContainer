#pragma once
#include <SFML/Graphics.hpp>

class particle{
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::CircleShape particleShape;

    float velocity,tempPos;

    public:
        float radius;
        float mass;

        particle(float posX, float posY, float velX, float velY, float radius, float mass);
        sf::Vector2f getPos();
        sf::Vector2f getVel();
        float getRadius();
        void updateVel(float vx, float vy, float dt);
        void render(sf::RenderWindow &window);
        void updatePos(float dt);
};

#include "particle.cpp"