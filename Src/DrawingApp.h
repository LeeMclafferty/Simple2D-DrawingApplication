#pragma once
#include "GuiManager.h"

class DrawingApp
{
public:
	DrawingApp(sf::RenderWindow& mainWindow, GuiManager& gManager, ShapeTool& tool);
	void MainLoop();

private:

	sf::RenderWindow& window;
	GuiManager& guiManager;
	ShapeTool& shapeTool;

	tgui::Gui& GetGui() { return guiManager.GetGui(); }

	std::vector<std::shared_ptr<sf::Shape>> shapes;
	bool isDrawing = false;

	const float thresholdSeconds;
	sf::Clock clickTimer;

	bool IsOverButton();

};

