#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "ShapeTool.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Drawing");

    std::vector<std::unique_ptr<sf::Shape>> shapes;
    bool isDrawing = false;

    ShapeTool shapeTool;
    shapeTool.SetSelectedShape(ShapeTool::CIRCLE);
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
                shapes.push_back(shapeTool.createShape(shapeTool.getSelectedShapeType(),
                    sf::Color::Green, 0.f, sf::Color::Transparent));
            }
        }

        if (isDrawing)
        {
            shapeTool.setCurrentSize(window.mapPixelToCoords(sf::Mouse::getPosition(window)) - shapeTool.getStartPosition());
        }

        window.clear(sf::Color::White);

        for (const auto& shape : shapes)
        {
            window.draw(*shape);
        }

        if (isDrawing)
        {
            auto currentShape = shapeTool.createShape(shapeTool.getSelectedShapeType(), 
                sf::Color::Transparent, 5.f, sf::Color::Black);
            //currentShape->setPosition(shapeTool.getStartPosition());
            window.draw(*currentShape);
        }
        
        window.display();
    }
    return 0;
}
