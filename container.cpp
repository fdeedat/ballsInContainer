#include "container.h"

container::container(float x, float y, float wallThickness, float width, float height) {
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

void container::setPosition(float x, float y) {
    // Left wall position
    leftWall.setPosition(x, y);

    // Right wall position
    rightWall.setPosition(x + boxWidth , y);

    // Bottom wall position
    bottomWall.setPosition(x, y + boxHeight - wallThickness);
}

void container::draw(sf::RenderWindow &window) {
    window.draw(leftWall);
    window.draw(rightWall);
    window.draw(bottomWall);
}

sf::Vector2f container::getLeftWallPos(){
    float innerLeftWallx = leftWall.getPosition().x + wallThickness;
    return sf::Vector2f(innerLeftWallx,leftWall.getPosition().y);
}

sf::Vector2f container::getBottomWallPos(){
    float innerBottomWally = bottomWall.getPosition().y;
    return sf::Vector2f(bottomWall.getPosition().x,innerBottomWally);
}

sf::Vector2f container::getRightWallPos(){
    float innerRightWallx = rightWall.getPosition().x - wallThickness;
    return sf::Vector2f(innerRightWallx,rightWall.getPosition().y);
}