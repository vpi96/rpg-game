#include "Player.h"
#include <iostream>
#include "Skeleton.h"
#include "math.h"


void Player::Initialize()
{

}

void Player::Load()
{
    if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player Image Loaded!" << std::endl;
        sprite.setTexture(texture);

        int XIndex = 0;
        int YIndex = 0;
        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        sprite.scale(sf::Vector2f(1, 1));
        sprite.setPosition(sf::Vector2f(0, 0));

    }
    else
    {
        std::cout << "Player image faild to load!" << std::endl;
    }

}

void Player::Update(Skeleton& skeleton)
{

    sf::Vector2f position = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.setPosition(position + sf::Vector2f(1, 0));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.setPosition(position + sf::Vector2f(0, -1));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.setPosition(position + sf::Vector2f(0, 1));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.setPosition(position + sf::Vector2f(-1, 0));

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));

        int i = bullets.size() - 1;
        bullets[i].setPosition(player.sprite.getPosition());
    }

    for (int i = 0; i < bullets.size(); i++)
    {
        sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
        bulletDirection = Math::NormalizeVector(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
    }

}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);

    for (int i = 0; i < bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }
}







