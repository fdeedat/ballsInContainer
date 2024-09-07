#include <iostream>
#include <particle.h>
#include <engine.h>

sf::RenderWindow window(sf::VideoMode(800, 800), "Particle Physics",sf::Style::Titlebar | sf::Style::Close);

int main()
{
    engine e;
    particle p1(350.0f,200.0f,50.0f,0.0f,3.0f,3.0f); e.addParticle(p1);
    particle p2(450.0f,200.0f,-50.0f,0.0f,3.0f,3.0f); e.addParticle(p2);

    sf::Clock clock;
    window.setFramerateLimit(120);
    sf::Time deltaTime;

    while (window.isOpen())
    {
        sf::Event event;
        
        window.clear();
        
        deltaTime = clock.restart();
        float dt = deltaTime.asSeconds(); // This makes the simulation more accurate
        e.updateDynamics(p1,dt,window);
        // p1.updatePos(dt);
        // p1.render(window);
        window.display();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close(); //closes the window
        }
    }
    return 0;
}
