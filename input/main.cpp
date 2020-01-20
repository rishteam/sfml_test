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
        sf::String s;
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            // Window events
            case sf::Event::Closed:
                window.close();
            break;

            case sf::Event::Resized:
            {
                printf("ResizeEvent: W=%d H=%d\n", event.size.width, event.size.height);
            }
            break;

            case sf::Event::LostFocus:
                printf("LostFocusEvent: The window just lost focus\n");
            break;

            case sf::Event::GainedFocus:
                printf("GainedFocusEvent: The window gained focus\n");
            break;
            // Keyboard events
            case sf::Event::KeyPressed:
            case sf::Event::KeyReleased:
            {
                printf("KeyEvent: ");
                printf("%s ", event.type == sf::Event::KeyPressed ? "Pressed" : "Release");
                printf("%s ", toString(event.key.code).c_str());
                // Combination keys
                if(event.key.control || event.key.alt || event.key.shift || event.key.system) printf("    With ");
                if(event.key.control) printf("Control");
                if(event.key.alt) printf("Alt");
                if(event.key.shift) printf("Shift");
                if(event.key.system) printf("System");
                puts("");
            }
            break;

            case sf::Event::TextEntered:
            {
                // s += event.text.unicode;
                // std::wcout << s.toWideString() << '\n';
            }
            break;
            // Mouse events
            case sf::Event::MouseButtonPressed:
            case sf::Event::MouseButtonReleased:
            {
                printf("MouseButtonEvent: ");
                printf("%s ", event.type == sf::Event::MouseButtonPressed ? "Pressed" : "Release");
                printf("%s %d %d", toString(event.mouseButton.button).c_str(), event.mouseButton.x, event.mouseButton.y);
                puts("");
            }
            break;

            case sf::Event::MouseMoved:
            {
                printf("MouseMovedEvent: x=%d y=%d\n", event.mouseMove.x, event.mouseMove.y);
            }
            break;

            case sf::Event::MouseEntered:
                printf("Mouse entered the window\n");
            break;

            case sf::Event::MouseLeft:
                printf("Mouse left the window\n");
            break;

            case sf::Event::MouseWheelScrolled:
            {
                // static const char *dir[] = {""}
                printf("MouseWheelEvent: ");
                printf("%s delta=%f @ x=%d y=%d\n",
                    toString(event.mouseWheelScroll.wheel).c_str(),
                    event.mouseWheelScroll.delta,
                    event.mouseWheelScroll.x,
                    event.mouseWheelScroll.y
                );
            }
            break;

            default:
                if(event.type != sf::Event::MouseWheelMoved)
                printf("UNHANDLED EVENT HAPPENED\n");
            break;
            }
        }
        /* Render */
        window.clear();

        window.display();
    }
}