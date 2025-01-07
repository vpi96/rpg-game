#pragma once
#include <SFML/graphics.hpp>

class Skeleton
{
private:

	sf::Texture texture;

public:
	sf::Sprite sprite;


public:

	void Initialize();
	void Load();
	void Update();
	void Draw(sf::RenderWindow& window);

};

