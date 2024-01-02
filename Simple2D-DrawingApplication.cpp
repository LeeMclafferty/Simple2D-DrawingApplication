#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "ShapeTool.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Drawing");

    std::vector<sf::RectangleShape> rectangles;
    bool isDrawing = false;

    ShapeTool shapeTool;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left)
            {
                shapeTool.setStartPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
                isDrawing = true;
            }
            else if (event.type == sf::Event::MouseButtonReleased &&
                event.mouseButton.button == sf::Mouse::Left)
            {
                isDrawing = false;
                sf::RectangleShape newRect = shapeTool.createRectangel();
                rectangles.push_back(newRect);
            }
        }

        if (isDrawing)
        {
            shapeTool.setCurrentSize(window.mapPixelToCoords(sf::Mouse::getPosition(window)) - shapeTool.getStartPosition());
        }

        window.clear(sf::Color::White);

        for (const auto& rect : rectangles)
        {
            window.draw(rect);
        }

        if (isDrawing)
        {
            sf::RectangleShape currentRect;
            currentRect.setPosition(shapeTool.getStartPosition());
            currentRect.setSize(shapeTool.getCurrentSize());
            currentRect.setFillColor(sf::Color::Transparent);
            currentRect.setOutlineThickness(5.f);
            currentRect.setOutlineColor(sf::Color::Black);
            window.draw(currentRect);
        }

        window.display();
    }
    return 0;
}
