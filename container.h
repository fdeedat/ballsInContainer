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
        // Constructor to initialize the U-shape with given dimensions
        container(float x, float y, float wallThickness, float width, float height);
        // Method to easily manipulate the position of the U-shaped box
        void setPosition(float x, float y);
        // Draw the U-shaped box onto the given render window
        void draw(sf::RenderWindow &window);
};
#include "container.cpp"