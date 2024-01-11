#include "DrawingDataSaver.h"
#include <fstream>
#include <iostream>
#include "ShapeTool.h"
#include <cereal/archives/binary.hpp>

DrawingDataSaver::DrawingDataSaver(const std::string& filename)
{
	path = "D:/Dev/LocalRepos/Simple2D-DrawingApplication/SavedDrawing/" + filename;
}


void DrawingDataSaver::Save(const std::vector<std::shared_ptr<sf::Shape>>&shapes) 
{
	std::ofstream os(path, std::ios::binary);
	cereal::BinaryOutputArchive archive(os);
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

