#include "GuiManager.h"
#include <TGUI/Widgets/BitmapButton.hpp>
#include <TGUI/Texture.hpp>
#include <TGUI/Widgets/ColorPicker.hpp>

GuiManager::GuiManager(sf::RenderWindow& rWindow, tgui::Gui& mainGui, ShapeTool& tool)
	: window(rWindow), gui(mainGui), toolButtonSpacing(rWindow.getSize().x / 15), shapeTool(tool)
{
	int buttonSize = window.getSize().x / 20;
	CreateButton("RectangleTool", { buttonSize, buttonSize },"Textures/RectangleTool.png", &GuiManager::OnClickRectangleTool);
	CreateButton("TriangleTool", { buttonSize, buttonSize }, "Textures/TriangleTool.png", &GuiManager::OnClinckTriangleTool);
	CreateButton("CircleTool", { buttonSize, buttonSize }, "Textures/CircleTool.png", &GuiManager::OnClickCircleTool);
	CreateButton("LineTool", { buttonSize, buttonSize }, "Textures/LineTool.png", &GuiManager::OnClickLineTool);
	CreateButton("ColorPickerTool", { buttonSize, buttonSize }, "Textures/ColorPickerTool.png", &GuiManager::OnClickColorPickerTool);
	AddButtonsToGui();

	
}

void GuiManager::CreateButton(std::string buttonName, sf::Vector2i buttonSize, std::string tPath, void (GuiManager::* OnClick)())
{
	tgui::Texture texture(tPath);
	tgui::BitmapButton::Ptr button = tgui::BitmapButton::create();
	button->setSize(buttonSize.x, buttonSize.y);	
	button->getRenderer()->setTexture(texture);
	button->getRenderer()->setBorderColor(tgui::Color::Transparent);
	button->onClick([this, OnClick] { (this->*OnClick)(); });
	buttons[buttonName] = button;
}


void GuiManager::AddButtonsToGui()
{
	int buttonX = 5;
	int buttonY = 50;
	for (auto& buttonPair : buttons)
	{
		tgui::BitmapButton::Ptr button = buttonPair.second;
		button->setPosition(buttonX, buttonY);
		buttonY += toolButtonSpacing;
		gui.add(button);
	}
}

void GuiManager::OnClickRectangleTool()
{
	shapeTool.setSelectedShapeType(ShapeTool::RECTANGLE);
}

void GuiManager::OnClinckTriangleTool()
{
	shapeTool.setSelectedShapeType(ShapeTool::TRIANGLE);
}

void GuiManager::OnClickCircleTool()
{
	shapeTool.setSelectedShapeType(ShapeTool::CIRCLE);
}

void GuiManager::OnClickLineTool()
{
	shapeTool.setSelectedShapeType(ShapeTool::LINE);
}

void GuiManager::OnClickColorPickerTool()
{
	canDraw = false;
	tgui::ColorPicker::Ptr colorPicker = tgui::ColorPicker::create();
	//tgui::Signal::connect(&Test);
	gui.add(colorPicker);
}

void GuiManager::Test()
{
	std::cout << "Test" << "\n";
}

