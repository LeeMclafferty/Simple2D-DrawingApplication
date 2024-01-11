#include "DrawingDataLoader.h"
#include <fstream>
#include <iostream>
#include "ShapeTool.h"
#include <cereal/archives/binary.hpp>

DrawingDataLoader::DrawingDataLoader(const std::string& filename)
{
	path = "D:/Dev/LocalRepos/Simple2D-DrawingApplication/SavedDrawing/" + filename;
}

void DrawingDataLoader::Load(std::vector<std::shared_ptr<sf::Shape>>& shapes) 
{

	std::ifstream is(path, std::ios::binary);
	if (!is) 
	{
		throw std::runtime_error("Could not open file for reading: " + path);
	}

	cereal::BinaryInputArchive archive(is);

	for (const auto& shapePtr : shapes)
	{
		if (std::shared_ptr<sf::RectangleShape> derivedPtr = std::dynamic_pointer_cast<sf::RectangleShape>(shapePtr))
		{
			archive(derivedPtr);
		}
		if (std::shared_ptr<sf::CircleShape> derivedPtr = std::dynamic_pointer_cast<sf::CircleShape>(shapePtr))
		{
			archive(derivedPtr);
		}
	}
}
