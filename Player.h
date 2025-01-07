#pragma once
#include <SFML/graphics.hpp>

class Player
{
private:

	sf::Texture texture;

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.5f;

public:
	sf::Sprite sprite;


public:

	void Initialize();
	void Load();
	void Update(Skeleton& skeleton);
	void Draw(sf::RenderWindow& window);

};