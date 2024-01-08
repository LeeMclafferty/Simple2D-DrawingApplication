#pragma 
#include <SFML/Graphics.hpp>

class ShapeTool
{
public:
	enum Shape
	{
		RECTANGLE,
		CIRCLE,
		TRIANGLE,
		LINE
	};

	ShapeTool();
	std::unique_ptr<sf::Shape> createShape(Shape shape, sf::Color color, float outlineThickness, sf::Color outlineColor);

	void setStartPosition(sf::Vector2f pos);
	void setEndPosition(sf::Vector2f pos);
	void setSelectedShapeType(Shape shape);
	void setSelectedColor(sf::Color color);

	sf::Vector2f getStartPosition() { return startPosition; }
	sf::Vector2f getendPosition() { return endPosition; }
	Shape getSelectedShapeType() { return selectedShapeType; }
	sf::Color GetSelectedColor() { return selectedColor; }

private:
	sf::Vector2f startPosition;
	sf::Vector2f endPosition;
	Shape selectedShapeType;
	sf::Color selectedColor;
};

