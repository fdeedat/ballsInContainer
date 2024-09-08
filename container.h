#pragma once
#include "particle.h"

class container {

    sf::RectangleShape leftWall;
    sf::RectangleShape rightWall;
    sf::RectangleShape bottomWall;
    
    float wallThickness;
    float boxWidth;
    float boxHeight;

    public:    
        container(float x, float y, float wallThickness, float width, float height);
        void setPosition(float x, float y); 
        void draw(sf::RenderWindow &window);
        sf::Vector2f getLeftWallPos();
        sf::Vector2f getRightWallPos();
        sf::Vector2f getBottomWallPos();
};
#include "container.cpp"