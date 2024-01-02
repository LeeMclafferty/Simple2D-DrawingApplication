#include "ShapeTool.h"

ShapeTool::ShapeTool()
{

}

void ShapeTool::setStartPosition(sf::Vector2f pos)
{
	startPosition = pos;
}

void ShapeTool::setCurrentSize(sf::Vector2f pos)
{
	currentSize = pos;
}

sf::RectangleShape ShapeTool::createRectangel()
{
	sf::RectangleShape newRect;
	newRect.setPosition(startPosition);
	newRect.setSize(currentSize);
	newRect.setFillColor(sf::Color::Green);

	return newRect;
}

