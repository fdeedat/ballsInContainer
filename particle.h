#pragma once
#include <SFML/Graphics.hpp>

class particle{
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::CircleShape particleShape;

    public:
        float radius;
        float mass;

        particle(float posX, float posY, float velX, float velY, float radius, float mass);
        sf::Vector2f getPos();
        sf::Vector2f getVel();
        float getRadius();
        void updateVel(float vx, float vy);
        void render(sf::RenderWindow &window);
        void updatePos(float dt);
};

class container {
    private:
        sf::RectangleShape leftWall;
        sf::RectangleShape rightWall;
        sf::RectangleShape bottomWall;
        
        float wallThickness;
        float boxWidth;
        float boxHeight;

    public:
        // Constructor to initialize the U-shape with given dimensions
        container(float x, float y, float wallThickness, float width, float height) {

            this->wallThickness = wallThickness;
            this->boxWidth = width;
            this->boxHeight = height;

            // Left wall
            leftWall.setSize(sf::Vector2f(wallThickness, height));
            leftWall.setFillColor(sf::Color::White);

            // Right wall
            rightWall.setSize(sf::Vector2f(wallThickness, height));
            rightWall.setFillColor(sf::Color::White);

            // Bottom wall
            bottomWall.setSize(sf::Vector2f(width, wallThickness));
            bottomWall.setFillColor(sf::Color::White);

            // Set the initial position of the U-shape
            setPosition(x, y);
        }

        // Method to easily manipulate the position of the U-shaped box
        void setPosition(float x, float y) {
            // Left wall position
            leftWall.setPosition(x, y);

            // Right wall position
            rightWall.setPosition(x + boxWidth , y);

            // Bottom wall position
            bottomWall.setPosition(x, y + boxHeight - wallThickness);
        }

        // Draw the U-shaped box onto the given render window
        void draw(sf::RenderWindow &window) {
            window.draw(leftWall);
            window.draw(rightWall);
            window.draw(bottomWall);
        }
};

#include "particle.cpp"