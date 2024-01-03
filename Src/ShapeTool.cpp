#include "ShapeTool.h"
#include "MathHelpers.h"

ShapeTool::ShapeTool()
	:startPosition(sf::Vector2f(0, 0)), endPosition(sf::Vector2f(0,0)), selectedShapeType(Shape::RECTANGLE)
{

}

void ShapeTool::setStartPosition(sf::Vector2f pos)
{
	startPosition = pos;
}

void ShapeTool::setEndPosition(sf::Vector2f pos)
{
	endPosition = pos;
}

void ShapeTool::setSelectedShapeType(Shape shape)
{
	selectedShapeType = shape;
}


std::unique_ptr<sf::Shape> ShapeTool::createShape(Shape shape, sf::Color color, float outlineThickness = 0, sf::Color outlineColor = sf::Color::Black)
{
	sf::RectangleShape newRect;
	sf::CircleShape newShape;

	if (selectedShapeType == RECTANGLE)
	{
		newRect.setPosition(startPosition);
		newRect.setSize(endPosition);
		newRect.setFillColor(color);
		newRect.setOutlineThickness(outlineThickness);
		newRect.setOutlineColor(outlineColor);
		return std::make_unique<sf::RectangleShape>(newRect);
	}
	else if (selectedShapeType == CIRCLE)
	{
		float diameter = sqrt(pow(endPosition.x - startPosition.x, 2) + pow(endPosition.y - startPosition.y, 2));
		float radius = diameter / 2;
		newShape.setRadius(radius);
		newShape.setPosition(startPosition);
		newShape.setFillColor(color);
		newShape.setOutlineThickness(outlineThickness);
		newShape.setOutlineColor(outlineColor);
		return std::make_unique<sf::CircleShape>(newShape);
	}
	else if (selectedShapeType == TRIANGLE)
	{
		newShape.setPointCount(3);
		float diameter = sqrt(pow(endPosition.x - startPosition.x, 2) + pow(endPosition.y - startPosition.y, 2));
		float radius = diameter / 2;
		newShape.setRadius(radius);
		newShape.setPosition(startPosition);
		newShape.setFillColor(color);
		newShape.setOutlineThickness(outlineThickness);
		newShape.setOutlineColor(outlineColor);
		return std::make_unique<sf::CircleShape>(newShape);
	}
	else if (selectedShapeType == LINE)
	{	
		float length = sqrt(pow(endPosition.x - startPosition.x, 2) + pow(endPosition.y - startPosition.y, 2));
		float thickness = 2; 
		newRect.setSize(sf::Vector2f(length, thickness));
		newRect.setRotation(MathHelpers::getAngle(startPosition.x, startPosition.y, endPosition.x, endPosition.y));
		newRect.setFillColor(sf::Color::Green);
		newRect.setPosition(startPosition);
		return std::make_unique<sf::RectangleShape>(newRect);
	}

	return std::make_unique<sf::RectangleShape>();
}

