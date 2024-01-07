#include "GuiManager.h"
#include <TGUI/Widgets/BitmapButton.hpp>
#include <TGUI/Texture.hpp>

GuiManager::GuiManager(sf::RenderWindow& rWindow, tgui::Gui& mainGui)
	:window(rWindow), gui(mainGui), toolButtonSpacing(30)
{
	int buttonSize = 200;
	CreateButton("RectangleTool", { buttonSize, buttonSize }, sf::Color(0, 0, 225));
	CreateButton("TriangleTool", { buttonSize, buttonSize }, sf::Color(0, 255, 0));
	CreateButton("CircleTool", { buttonSize, buttonSize }, sf::Color(255, 0, 0));
	CreateButton("LineTool", { buttonSize, buttonSize }, sf::Color(0, 0, 0));
	AddButtonsToGui();
}

void GuiManager::CreateButton(std::string buttonName, sf::Vector2i buttonSize, sf::Color buttonColor)
{
	tgui::BitmapButton::Ptr button = tgui::BitmapButton::create();
	button->setSize(25, 25);
	button->getRenderer()->setBackgroundColor(buttonColor);
	buttons[buttonName] = button;
}

void GuiManager::AddButtonsToGui()
{
	int buttonX = 5;
	int buttonY = 5;
	for (auto& buttonPair : buttons)
	{
		tgui::Button::Ptr button = buttonPair.second;
		button->setPosition(buttonX, buttonY);
		buttonY += 30;
		gui.add(button);
	}
}
