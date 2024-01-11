#include "DrawingApp.h"
#include <SFML/Graphics.hpp>

DrawingApp::DrawingApp(sf::RenderWindow& mainWindow, GuiManager& gManager, ShapeTool& tool)
	: window(mainWindow), guiManager(gManager), shapeTool(tool), thresholdSeconds(.25f)
{
	shapeTool.setSelectedShapeType(ShapeTool::RECTANGLE);

	renderTexture.create(window.getSize().x, window.getSize().y);
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
				if (!IsOverButton() && guiManager.canDraw)
				{
					isDrawing = true;
				}
			}
			else if (event.type == sf::Event::MouseButtonReleased &&
				event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2f pixelPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				if (!IsOverButton() && isDrawing && shapeTool.getSelectedShapeType() != ShapeTool::FREEFORM)
				{
					shapes.push_back(shapeTool.createShape(shapeTool.getSelectedShapeType(),
						shapeTool.GetSelectedColor(), 0.f, sf::Color::Transparent));
				}
				isDrawing = false;
			}
		}

		if (isDrawing && !IsOverButton())
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

		// Outline
		if (isDrawing && !IsOverButton())
		{
			if (shapeTool.getSelectedShapeType() == ShapeTool::FREEFORM)
			{
				sf::Vector2f pixelPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				sf::RectangleShape pixel(sf::Vector2f(5.f, 5.f));
				pixel.setFillColor(shapeTool.GetSelectedColor());
				pixel.setPosition(pixelPosition);

				renderTexture.draw(pixel);

				renderTexture.display();
			}
			else
			{
				auto currentShape = shapeTool.createShape(shapeTool.getSelectedShapeType(),
					sf::Color::Transparent, 5.f, sf::Color::Black);
				currentShape->setPosition(shapeTool.getStartPosition());
				window.draw(*currentShape);
			}

		}

		sf::Sprite renderSprite(renderTexture.getTexture());
		window.draw(renderSprite);

		GetGui().draw();
		window.display();
	}
}

bool DrawingApp::IsOverButton()
{
	bool isCursorOverButton = false;
	sf::Vector2f cursorPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	for (const auto& buttonPair : guiManager.GetButtons())
	{
		tgui::BitmapButton::Ptr button = buttonPair.second;
		sf::FloatRect buttonBounds({ button->getPosition().x, button->getPosition().y }, {button->getSize().x,
			button->getSize().y});

		if (buttonBounds.contains(cursorPosition))
		{
			isCursorOverButton = true;
			break;
		}
	}

	return isCursorOverButton;
}
