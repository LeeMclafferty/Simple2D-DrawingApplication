// Simple2D-DrawingApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Drawing");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            window.clear(sf::Color::White);

            // draw here
            sf::CircleShape shape(50.f);
            //shape.setFillColor(sf::Color(100, 204, 20));
            shape.setOutlineThickness(2.f);
            shape.setOutlineColor(sf::Color(0, 0, 0));
            shape.setPosition(200, 200);
            sf::Texture texture;
            texture.loadFromFile("Textures/T_Brick512x512.jpg");
            shape.setTexture(&texture);

            window.draw(shape);
            window.display();
        }
    }
    return 0;
}