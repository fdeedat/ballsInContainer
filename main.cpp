#include <iostream>
#include <particle.h>
#include <engine.h>
#include <container.h>

sf::RenderWindow window(sf::VideoMode(800, 800), "Particle Physics",sf::Style::Titlebar | sf::Style::Close);

int main()
{
    bool isPaused = 0;
    engine e;
    e.createParticles(1000, sf::Vector2f(200, 600), sf::Vector2f(0, 0),3);

    container c(200.0f,600.0f,5.0f,500.0f,100.0f);
    // container c(1,0,5,795,800);

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
            isPaused = !isPaused; //idk why but apperently you need to hold the space button????
        }
        
        if(isPaused == false) {
            e.updateDynamics(dt,window,c);
            c.draw(window);
            window.display();
        }
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            c.setPosition(mousePos.x,mousePos.y);
        }

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close(); //closes the window
        }
    }
    return 0;
}
