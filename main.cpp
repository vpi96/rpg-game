#include <iostream>
#include <SFML/graphics.hpp>
#include <vector>
#include <math.h>

sf::Vector2f NormalizeVector(sf::Vector2f vector)
{
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    sf::Vector2f normalizedVector;

    normalizedVector.x = vector.x / m;
    normalizedVector.y = vector.y / m;

    return normalizedVector;
   
}

int main()
{
    //--------------------------------- INITIALIZE -------------------------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "rpg game", sf::Style::Default, settings);



    //--------------------------------- INITIALIZE -------------------------------------

    std::vector<sf::RectangleShape> bullets;
    float bulletSpeed = 0.5f;
    sf::Vector2f bulletDirection;

    //--------------------------------- LOAD -------------------------------------------

    //--------------------------------- SKELETON -------------------------------------------
    sf::Texture skeletonTexture;
    sf::Sprite skeletonSprite;

    if (skeletonTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
    {
        std::cout << "Enemy Image Loaded!" << std::endl;
        skeletonSprite.setTexture(skeletonTexture);
        skeletonSprite.setPosition(sf::Vector2f(1600, 700));

        // Int
        // X, Y, Width, Height
        int XIndex = 0;
        int YIndex = 2;
        skeletonSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        skeletonSprite.scale(sf::Vector2f(1, 1));

    }

    else
    {
        std::cout << "Enemy image faild to load!" << std::endl;
    }

    //--------------------------------- SKELETON -------------------------------------------


    //--------------------------------- PLAYER -------------------------------------------

    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png")) 
    {
        std::cout << "Player Image Loaded!" << std::endl;
        playerSprite.setTexture(playerTexture);

        // Int
        // X, Y, Width, Height
        int XIndex = 0;
        int YIndex = 0;
        playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        playerSprite.scale(sf::Vector2f(1, 1));
        playerSprite.setPosition(sf::Vector2f(0, 0));

    }
    else
    {
        std::cout << "Player image faild to load!" << std::endl;
    }

    //--------------------------------- PLAYER -------------------------------------------

    //--------------------------------- LOAD ---------------------------------------------

    //bullet.setPosition(playerSprite.getPosition());


    //--------------------------------- Calculate the direction of the bullet ------------

    //sf::Vector2f bulletDirection = skeletonSprite.getPosition() - bullet.getPosition();
    //bulletDirection = NormalizeVector(bulletDirection);

    //--------------------------------- Calculate the direction of the bullet ------------



    //main game loop
    while (window.isOpen())
    {

        //--------------------------------- UPDATE -------------------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //bullet.setPosition(bullet.getPosition() + bulletDirection * bulletSpeed);

        sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(1, 0));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            playerSprite.setPosition(position + sf::Vector2f(0, -1));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            playerSprite.setPosition(position + sf::Vector2f(0, 1));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));

            int i = bullets.size() - 1;
            bullets[i].setPosition(playerSprite.getPosition());
        }

        for (int i = 0; i < bullets.size(); i++)
        {
            bulletDirection = skeletonSprite.getPosition() - bullets[i].getPosition();
            bulletDirection = NormalizeVector(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
        }

        //--------------------------------- UPDATE -------------------------------------

        //--------------------------------- DRAW -------------------------------------

        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.draw(skeletonSprite);

        for (int i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
        //window.draw(bullet);
        window.display();

        //--------------------------------- DRAW -------------------------------------
    }
    return 0;
}


