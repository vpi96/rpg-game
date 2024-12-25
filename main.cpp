#include <iostream>
#include <SFML/graphics.hpp>

int main()
{
    //--------------------------------- initialize -------------------------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "rpg game", sf::Style::Default, settings);

    sf::CircleShape shape(50.0f, 5);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(sf::Vector2f(100, 100));
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color::Green);

    sf::RectangleShape rectangle(sf::Vector2f(200, 1));
    rectangle.setPosition(sf::Vector2f(300, 100));
    rectangle.setFillColor(sf::Color::Blue);
    //rectangle.setorigin(sf::vector2f(rectangle.getsize() / 2.0f));
    //rectangle.setrotation(45);

    sf::CircleShape octagon(100.f, 8);
    octagon.setFillColor(sf::Color::Yellow);
    octagon.setPosition(250, 250);


    //--------------------------------- initialize -------------------------------------

    while (window.isOpen())
    {
        //--------------------------------- update -------------------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                //std::cout << "haha! loser!!!" << std::endl;
                window.close();
            }
        }

        //--------------------------------- update -------------------------------------

        //--------------------------------- draw -------------------------------------

        window.clear(sf::Color::Black);
        window.draw(shape);
        window.draw(rectangle);
        window.draw(octagon);
        window.display();

        //--------------------------------- draw -------------------------------------
    }
    return 0;
}



//#include <SFML/Graphics.hpp>
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//
//    sf::Event event;
//    while (window.isOpen())
//    {
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }
//}

