#pragma once
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "ShapeTool.h"

class GuiManager
{
public:
	GuiManager(sf::RenderWindow& rWindow, tgui::Gui& mainGui, ShapeTool& tool);

	tgui::Gui& GetGui() { return gui; }
	std::unordered_map<std::string, tgui::BitmapButton::Ptr> GetButtons() { return buttons; }

	bool canDraw = true;

private:
	tgui::Gui& gui;
	sf::RenderWindow& window;
	ShapeTool& shapeTool;
	int toolButtonSpacing;
	
	void CreateTextureButton(std::string buttonName, std::string tPath, sf::Vector2i buttonSize, void (GuiManager::* OnClick)());
	void CreateColorButton(tgui::Color color, std::string buttonName, sf::Vector2i buttonSize, void (GuiManager::* OnClick)());

	void AddButtonsToGui();
	std::unordered_map<std::string, tgui::BitmapButton::Ptr> buttons;

	void OnClickRectangleTool();
	void OnClinckTriangleTool();
	void OnClickCircleTool();
	void OnClickLineTool();
	void OnClickColorPickerTool();
	void handleOnOkayPressed(tgui::ColorPicker::Ptr colorPicker);
	sf::Color TguiColorToSfColor(const tgui::Color& tguiColor);
	void ResetButtonImages();
};

