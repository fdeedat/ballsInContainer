#include <iostream>
#include <particle.h>
#include <engine.h>
#include <container.h>

sf::RenderWindow window(sf::VideoMode(800, 800), "Particle Physics",sf::Style::Titlebar | sf::Style::Close);

int main()
{
    bool isPaused = 0;
    engine e;
    e.createParticles(1000, sf::Vector2f(10, 700), sf::Vector2f(50, 300),3);

    // container c(400.0f,400.0f,5.0f,500.0f,100.0f);
    container c(1,700,5,800,100);

    sf::Clock clock;
    window.setFramerateLimit(120);
    sf::Time deltaTime;

    while (window.isOpen())
    {
        sf::Event event;
        
        window.clear();
        
        deltaTime = clock.restart();
        float dt = deltaTime.asSeconds(); 

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            isPaused = !isPaused;
        }
        
        if(isPaused == false) {
            e.updateDynamics(dt,window,c);
            c.draw(window);
            window.display();
        }
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            // c.setPosition(mousePos.x,mousePos.y);
        }

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close(); //closes the window
        }
    }
    return 0;
}
