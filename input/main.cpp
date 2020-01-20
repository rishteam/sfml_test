#include <iostream>
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "key.h"

#define WINDOW_W 1280
#define WINDOW_H 720

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "SFML window");
    // window.setFramerateLimit(60);
    sf::Clock clock;

    // init
    clock.restart();
    // Start the game loop
    while (window.isOpen())
    {
        while(clock.getElapsedTime().asSeconds() < 1/60.f)
            sf::sleep(sf::milliseconds(5));
        clock.restart();
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            switch(event.type)
            {
            case sf::Event::Closed:
                window.close();
            break;

            case sf::Event::KeyPressed:
            case sf::Event::KeyReleased:
            {
                printf("Event: ");
                printf("%s ", event.type == sf::Event::KeyPressed ? "Pressed" : "Release");
                printf("%s ", toString(event.key.code).c_str());
                if(event.key.control || event.key.alt || event.key.shift || event.key.system) printf("    With ");
                if(event.key.control) printf("Control");
                if(event.key.alt) printf("Alt");
                if(event.key.shift) printf("Shift");
                if(event.key.system) printf("System");
                puts("");
            }
            break;

            }
        }


        /* Render */
        window.clear();

        window.display();
    }
}