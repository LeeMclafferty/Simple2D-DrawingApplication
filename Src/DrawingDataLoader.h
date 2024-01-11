#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "SFMLSerialization.h"

class DrawingDataLoader
{
public:
	DrawingDataLoader(const std::string& filename);
	void Load(std::vector<std::shared_ptr<sf::Shape>>& shapes);
private:
	std::string path;
};


