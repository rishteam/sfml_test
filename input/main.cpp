#include <iostream>
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "key.h"

#define WINDOW_W 1280
#define WINDOW_H 720

sf::Font g_font;

class KeyButton
{
public:
    enum TexType
    {
        Float,
        Press
    };
    static sf::Texture tex[2];
    static bool init;
    static void loadKeyTexture()
    {
        if(init) return;
        init = true;
        tex[Float].loadFromFile("assets/key_float.png");
        tex[Press].loadFromFile("assets/key_press.png");
    }
    //
    float m_x, m_y;
    sf::Keyboard::Key m_key;

    KeyButton(float x, float y, sf::Keyboard::Key key) : m_x(x), m_y(y), m_key(key)
    {
        loadKeyTexture();
        sprite.setPosition(x, y);
        sprite.setScale({0.5, 0.5});

        text.setString(toString(key));
        text.setFont(g_font);
        text.setCharacterSize(40);
        text.setPosition({m_x + 55, m_y + 35});
        text.setFillColor(sf::Color(0, 0, 0));
    }

    void setPos(float x, float y)
    {
        m_x = x;
        m_y = y;
    }

    void update()
    {
        if(sf::Keyboard::isKeyPressed(m_key))
            sprite.setTexture(KeyButton::tex[KeyButton::Float]);
        else
            sprite.setTexture(KeyButton::tex[KeyButton::Press]);
    }
    void draw(sf::RenderTarget &rt)
    {
        rt.draw(sprite);
        rt.draw(text);
    }
private:
    sf::Sprite sprite;
    sf::Text text;
};

bool KeyButton::init = false;
sf::Texture KeyButton::tex[2];

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "SFML window");
    window.setFramerateLimit(60);
    sf::Clock clock;

    g_font.loadFromFile("arial.ttf"); // load font

    // Create WASD key
    float kx = 100, ky = 350;
    std::vector<KeyButton> keys = {
        KeyButton(kx + 139, ky + 0, sf::Keyboard::W),
        KeyButton(kx + 0, ky + 146, sf::Keyboard::A),
        KeyButton(kx + 139, ky + 146, sf::Keyboard::S),
        KeyButton(kx + 278, ky + 146, sf::Keyboard::D)};

    sf::Texture t;
    t.loadFromFile("assets/m.png");
    sf::Sprite mouseCap;
    mouseCap.setTexture(t);

    // init
    clock.restart();
    // Start the game loop
    while (window.isOpen())
    {
        while(clock.getElapsedTime().asSeconds() < 1/60.f)
            sf::sleep(sf::milliseconds(1));
        clock.restart();
        // Process events
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

        // Real-time input
        for(auto & key: keys)
            key.update();

        // Update mouseCap
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        mouseCap.setPosition(pos.x - 93, pos.y - 196);

        /* Render */
        window.clear();

        for (auto &key : keys)
            key.draw(window);
        window.draw(mouseCap);

        // Prepare the info text
        char tmp[100];
        sf::String s = "real-time mouse pos\n";
        sprintf(tmp, "x=%d y=%d\n", pos.x, pos.y);
        s += tmp;
        sprintf(tmp, "%s %s %s", 
            sf::Mouse::isButtonPressed(sf::Mouse::Left) ? "L" : "",
            sf::Mouse::isButtonPressed(sf::Mouse::Middle) ? "M" : "",
            sf::Mouse::isButtonPressed(sf::Mouse::Right) ? "R" : ""
        );
        s += tmp;
        sf::Text info(s, g_font);

        window.draw(info);

        window.display();
    }
}