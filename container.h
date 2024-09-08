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
        void setPosition(float x, float y); // Manipulate the position of the U-shaped box
        void draw(sf::RenderWindow &window); // Draw the U-shaped box onto the given render window
};
#include "container.cpp"