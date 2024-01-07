#pragma once
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

class GuiManager
{
public:
	GuiManager(sf::RenderWindow& rWindow, tgui::Gui& mainGui);

	tgui::Gui& GetGui() { return gui; }

private:
	tgui::Gui& gui;
	sf::RenderWindow& window;
	int toolButtonSpacing;
	void CreateButton(std::string buttonName, sf::Vector2i buttonSize, sf::Color buttonColor);
	void AddButtonsToGui();
	std::unordered_map<std::string, tgui::Button::Ptr> buttons;
};

