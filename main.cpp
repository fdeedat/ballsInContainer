#include <iostream>
#include <particle.h>
#include <engine.h>
#include <container.h>

sf::RenderWindow window(sf::VideoMode(800, 800), "Particle Physics",sf::Style::Titlebar | sf::Style::Close);

int main()
{
    engine e;

    particle p1(350.0f,200.0f,50.0f,0.0f,3.0f,3.0f); e.addParticle(p1);
    particle p2(450.0f,200.0f,-50.0f,0.0f,3.0f,3.0f); e.addParticle(p2);
    particle p3(300.0f,200.0f,50.0f,0.0f,5.0f,5.0f); e.addParticle(p3);
    particle p4(500.0f,200.0f,-50.0f,0.0f,5.0f,5.0f); e.addParticle(p4);

    container c(400.0f,400.0f,5.0f,500.0f,100.0f);

    sf::Clock clock;
    window.setFramerateLimit(120);
    sf::Time deltaTime;

    while (window.isOpen())
    {
        sf::Event event;
        
        window.clear();
        
        deltaTime = clock.restart();
        float dt = deltaTime.asSeconds(); 
        e.updateDynamics(p1,dt,window,c);

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
