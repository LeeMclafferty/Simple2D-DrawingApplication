#pragma 
#include <SFML/Graphics.hpp>

class ShapeTool
{
public:
	ShapeTool();
	sf::RectangleShape createRectangel();

	void setStartPosition(sf::Vector2f pos);
	void setCurrentSize(sf::Vector2f pos);

	sf::Vector2f getStartPosition() { return startPosition; }
	sf::Vector2f getCurrentSize() { return currentSize; }

private:
	sf::Vector2f startPosition;
	sf::Vector2f currentSize;
};

