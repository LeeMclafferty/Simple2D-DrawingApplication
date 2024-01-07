#include "DrawingApp.h"
#include <SFML/Graphics.hpp>

DrawingApp::DrawingApp(sf::RenderWindow& mainWindow, GuiManager& gManager)
: window(mainWindow), guiManager(gManager)
{
	shapeTool.setSelectedShapeType(ShapeTool::RECTANGLE);
}

void DrawingApp::MainLoop()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			GetGui().handleEvent(event);
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
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Num1)
				{
					shapeTool.setSelectedShapeType(ShapeTool::RECTANGLE);
				}
				else if (event.key.code == sf::Keyboard::Num2)
				{
					shapeTool.setSelectedShapeType(ShapeTool::CIRCLE);
				}
				else if (event.key.code == sf::Keyboard::Num3)
				{
					shapeTool.setSelectedShapeType(ShapeTool::TRIANGLE);
				}
				else if (event.key.code == sf::Keyboard::Num4)
				{
					shapeTool.setSelectedShapeType(ShapeTool::LINE);
				}
			}
		}

		if (isDrawing)
		{
			auto shapeType = shapeTool.getSelectedShapeType();
			if (shapeType == ShapeTool::RECTANGLE)
			{
				shapeTool.setEndPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)) - shapeTool.getStartPosition());
			}
			else if (shapeType == ShapeTool::CIRCLE || shapeType == ShapeTool::TRIANGLE || shapeType == ShapeTool::LINE)
			{
				shapeTool.setEndPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
			}
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
			currentShape->setPosition(shapeTool.getStartPosition());
			window.draw(*currentShape);
		}

		GetGui().draw();
		window.display();
	}
}
