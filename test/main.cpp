#include <iostream>
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML window");

    std::string path = "frames/";
    const int num = 288; // 24 fps
    std::vector<sf::Texture> tex_v;
    std::vector<sf::Sprite> sprite_v;

    sf::Clock clock;

    sf::Clock play_clk;
    for(int i = 1; i <= num; i++)
    {
        sf::Texture t;
        char thName[10];
        sprintf(thName, "%03d", i);

        t.loadFromFile(path + "nico-" + thName + ".jpg");

        auto size = t.getSize();
        sf::Sprite s(t);
        s.setScale(1280.f/size.x, 720.f/size.y);
        sprite_v.push_back(s);
    }

    sf::Music nico;
    if(!nico.openFromFile("nico.ogg")) printf("Failed to open %s\n", "nico.mp3");

    nico.play();
    int nowCnt = 0;
    clock.restart();
    // Start the game loop
    while (window.isOpen())
    {
        while(clock.getElapsedTime().asSeconds() < 1/60.f);
        clock.restart();
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();

        // if(play_clk.getElapsedTime().asSeconds() >= 1/24.f)
        // {
        //     nowCnt++;
        //     if(nowCnt >= sprite_v.size()) nowCnt %= sprite_v.size();
        //     play_clk.restart();
        // }
        window.draw(sprite_v[nowCnt]);
        // Update the window
        window.display();
    }
}