#include <iostream>
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#define WINDOW_W 1280
#define WINDOW_H 720

class Animation
{
public:
    static const std::string path;

    Animation() = delete;
    Animation(std::string prefix, int count, std::string ext)
    {
        fps = 24;
        nowDraw = 0;
        totalCnt = count;
        playState = false;
        //
        char thName[10];

        for (int i = 1; i <= totalCnt; i++)
        {
            std::shared_ptr<sf::Texture> t = std::make_shared<sf::Texture>();
            std::shared_ptr<sf::Sprite> s = std::make_shared<sf::Sprite>();
            sprintf(thName, "%03d", i);
            t->loadFromFile(Animation::path + prefix + thName + ext);
            auto size = t->getSize();
            s->setTexture(*t);
            s->setScale(1280.f / size.x, 720.f / size.y);

            tex_v.push_back(t);
            sprite_v.push_back(s);
        }
    }

    void draw(sf::RenderWindow &window)
    {
        if (playState && clk.getElapsedTime().asSeconds() >= 1 / (float)fps)
        {
            // printf("%d/%d\n", nowDraw, totalCnt);
            clk.restart();
            if (++nowDraw >= totalCnt)
                nowDraw = 0;
        }
        // printf("%d/%d\n", nowDraw, totalCnt);
        window.draw(*sprite_v[nowDraw]);
    }

    void play()
    {
        playState = true;
    }
    void stop()
    {
        playState = false;
    }

    void reset()
    {
        nowDraw = 0;
        playState = false;
    }
private:
    std::vector<std::shared_ptr<sf::Texture>> tex_v;
    std::vector<std::shared_ptr<sf::Sprite>> sprite_v;
    sf::Clock clk;
    int fps;
    int nowDraw, totalCnt;
    bool playState;
};

const std::string Animation::path = "frames/";

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "SFML window");
    // window.setFramerateLimit(60);
    sf::Clock clock;

    sf::Music nico;
    if(!nico.openFromFile("nico.ogg")) printf("Failed to open %s\n", "nico.mp3");

    Animation ani("nico-", 288, ".jpg");

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
            if (event.type == sf::Event::Closed)
                window.close();
        }

        static bool spacePrev = false;
        static bool playing = false;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if(!spacePrev)
            {
                puts("Pressed");
                playing = !playing;
            }

            if(playing)
            {
                nico.play();
                ani.play();
            }
            else
            {
                nico.pause();
                ani.stop();
            }
        }
        spacePrev = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
        //
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            playing = false;
            ani.reset();
        }
        /* Render */
        window.clear();
        ani.draw(window);
        window.display();
    }
}