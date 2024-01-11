#pragma once
#include "SFMLSerialization.h"
#include <fstream>
#include <vector>
#include <memory>

class DrawingDataSaver {
public:
	DrawingDataSaver(const std::string& filename);
	void Save(const std::vector<std::shared_ptr<sf::Shape>>& shapes);

private:
	std::string path;
};
