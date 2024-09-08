#include <iostream>
#include <particle.h>
#include <engine.h>
#include <container.h>

sf::RenderWindow window(sf::VideoMode(800, 800), "Particle Physics",sf::Style::Titlebar | sf::Style::Close);

int main()
{
    engine e;
    // U-shape boundaries (3 rectangles)

    container c(400.0f,400.0f,5.0f,100.0f,100.0f);

    sf::Clock clock;
    window.setFramerateLimit(120);
    sf::Time deltaTime;

    while (window.isOpen())
    {
        sf::Event event;
        
        window.clear();
        
        deltaTime = clock.restart();
        float dt = deltaTime.asSeconds(); 

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            c.setPosition(mousePos.x,mousePos.y);
        }

        c.draw(window);
        window.display();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close(); //closes the window
        }
    }
    return 0;
}
