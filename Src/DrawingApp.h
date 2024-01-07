#pragma once
#include "ShapeTool.h"
#include "GuiManager.h"

class DrawingApp
{
public:
	DrawingApp(sf::RenderWindow& mainWindow, GuiManager& gManager);
	void MainLoop();

private:

	sf::RenderWindow& window;
	GuiManager& guiManager;

	tgui::Gui& GetGui() { return guiManager.GetGui(); }

	std::vector<std::unique_ptr<sf::Shape>> shapes;
	bool isDrawing = false;
	ShapeTool shapeTool;

};

