#include <iostream>
#include <particle.h>

sf::RenderWindow window(sf::VideoMode(800, 800), "Particle Physics",sf::Style::Titlebar | sf::Style::Close);

int main()
{
    particle p1(200.0f,200.0f,50.0f,0.0f,3.0f);
    sf::Clock clock;
    window.setFramerateLimit(120);
    sf::Time deltaTime;

    while (window.isOpen())
    {
        sf::Event event;
        
        window.clear();
        
        deltaTime = clock.restart();
        float dt = deltaTime.asSeconds(); // This makes the simulation more accurate
        p1.update(dt);
        p1.render(window);
        window.display();

        std::cout<<dt<<std::endl;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close(); //closes the window
        }
    }
    return 0;
}
