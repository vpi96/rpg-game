#include <iostream>
#include <SFML/graphics.hpp>

int main()
{
    //--------------------------------- INITIALIZE -------------------------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "rpg game", sf::Style::Default, settings);



    //--------------------------------- INITIALIZE -------------------------------------

    //--------------------------------- LOAD -------------------------------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png")) 
    {
        std::cout << "Player Images Loaded!" << std::endl;
        playerSprite.setTexture(playerTexture);

        // Int
        // X, Y, Width, Height
        int XIndex = 0;
        int YIndex = 0;
        playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        playerSprite.scale(sf::Vector2f(1, 1));

    }
    else
    {
        std::cout << "Player image faild to load!" << std::endl;
    }
    //--------------------------------- LOAD -------------------------------------

    //main game loop
    while (window.isOpen())
    {
        //--------------------------------- UPDATE -------------------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //if (event.type == sf::Event::KeyPressed)
            //{
            //    if (event.key.code == sf::Keyboard::D)
            //    {
            //        //0, 0
            //        sf::Vector2f position = playerSprite.getPosition();
            //        playerSprite.setPosition(position + sf::Vector2f(10, 0));

            //    }
            //}
        }



        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0.1, 0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, -0.15));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, 0.2));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(-0.25, 0));
        }

        //--------------------------------- UPDATE -------------------------------------

        //--------------------------------- DRAW -------------------------------------

        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.display();

        //--------------------------------- DRAW -------------------------------------
    }
    return 0;
}


