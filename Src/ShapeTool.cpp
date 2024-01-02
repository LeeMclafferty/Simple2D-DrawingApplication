#include "ShapeTool.h"

ShapeTool::ShapeTool()
	:startPosition(sf::Vector2f(0, 0)), currentSize(sf::Vector2f(0,0)), selectedShapeType(Shape::RECTANGLE)
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

void ShapeTool::SetSelectedShape(Shape shape)
{
	selectedShapeType = shape;
}


std::unique_ptr<sf::Shape> ShapeTool::createShape(Shape shape, sf::Color color, float outlineThickness = 0, sf::Color outlineColor = sf::Color::Black)
{
	sf::RectangleShape newRect;
	sf::CircleShape newShape;
	switch (selectedShapeType)
	{
	case RECTANGLE:
		newRect.setPosition(startPosition);
		newRect.setSize(currentSize);
		newRect.setFillColor(color);
		newRect.setOutlineThickness(outlineThickness);
		newRect.setOutlineColor(outlineColor);
		return std::make_unique<sf::RectangleShape>(newRect);
	case CIRCLE:
		float diameter = sqrt(pow(currentSize.x - startPosition.x, 2) + pow(currentSize.y - startPosition.y, 2));
		float radius = diameter / 2;
		newShape.setRadius(radius);
		newShape.setPosition(startPosition);
		newShape.setFillColor(color);
		newShape.setOutlineThickness(outlineThickness);
		newShape.setOutlineColor(outlineColor);
		return std::make_unique<sf::CircleShape>(newShape);
// 	case TRIANGLE:
// 		newShape.setRadius(50);
// 		newShape.setFillColor(color);
// 		newShape.setOutlineThickness(outlineThickness);
// 		newShape.setOutlineColor(outlineColor);
// 		return std::make_unique<sf::CircleShape>(newShape);
// 	case LINE:
// 		newRect.setPosition(startPosition);
// 		newRect.setSize(currentSize);
// 		newRect.setFillColor(sf::Color::Green);
// 		return std::make_unique<sf::RectangleShape>(newRect);
	}
	return std::make_unique<sf::RectangleShape>();
}

