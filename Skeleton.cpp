#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{
}

void Skeleton::Load()
{
    if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
    {
        std::cout << "Enemy Image Loaded!" << std::endl;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(1600, 700));

        int XIndex = 0;
        int YIndex = 2;
        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        sprite.scale(sf::Vector2f(1, 1));

    }

    else
    {
        std::cout << "Enemy image faild to load!" << std::endl;
    }
}

void Skeleton::Update()
{
}

void Skeleton::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
