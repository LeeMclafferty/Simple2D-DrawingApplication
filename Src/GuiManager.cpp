#include "GuiManager.h"
#include <TGUI/Widgets/BitmapButton.hpp>
#include <TGUI/Texture.hpp>
#include <TGUI/Widgets/ColorPicker.hpp>
#include <SFML/Graphics.hpp>
#include "TGUI/Color.hpp"

GuiManager::GuiManager(sf::RenderWindow& rWindow, tgui::Gui& mainGui, ShapeTool& tool)
	: window(rWindow), gui(mainGui), toolButtonSpacing(rWindow.getSize().x / 15), shapeTool(tool)
{
	int buttonSize = window.getSize().x / 20;
// 	CreateTextureButton("RectangleTool", "/Textures/RectangleTool.png", { buttonSize, buttonSize }, &GuiManager::OnClickRectangleTool);
// 	CreateTextureButton("TriangleTool", "/Textures/TriangleTool.png", { buttonSize, buttonSize },&GuiManager::OnClinckTriangleTool);
// 	CreateTextureButton("CircleTool", "/Textures/CircleTool.png", { buttonSize, buttonSize }, &GuiManager::OnClickCircleTool);
// 	CreateTextureButton("LineTool", "/Textures/LineTool.png", { buttonSize, buttonSize }, &GuiManager::OnClickLineTool);
// 	CreateColorButton(tgui::Color(shapeTool.GetSelectedColor()), "ColorPickerTool", {buttonSize, buttonSize}, &GuiManager::OnClickColorPickerTool);
	AddButtonsToGui();
}

void GuiManager::CreateTextureButton(std::string buttonName, std::string tPath, sf::Vector2i buttonSize, void (GuiManager::* OnClick)())
{
	tgui::Texture texture(tPath);
	tgui::BitmapButton::Ptr button = tgui::BitmapButton::create();
	button->setSize(buttonSize.x, buttonSize.y);
	button->getRenderer()->setTexture(texture);
	button->getRenderer()->setBorderColor(tgui::Color::Transparent);
	button->onClick([this, OnClick] { (this->*OnClick)(); });
	buttons[buttonName] = button;
}


void GuiManager::CreateColorButton(tgui::Color color, std::string buttonName, sf::Vector2i buttonSize, void (GuiManager::* OnClick)())
{
	tgui::BitmapButton::Ptr button = tgui::BitmapButton::create();
	button->setSize(buttonSize.x, buttonSize.y);
	button->getRenderer()->setBorderColor(tgui::Color::Black);
	button->getRenderer()->setBackgroundColor(color);
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
	ResetButtonImages();
	buttons["RectangleTool"]->getRenderer()->setTexture("Textures/RectangleTool-s.png");
	shapeTool.setSelectedShapeType(ShapeTool::RECTANGLE);
}

void GuiManager::OnClinckTriangleTool()
{
	ResetButtonImages();
	buttons["TriangleTool"]->getRenderer()->setTexture("Textures/TriangleTool-s.png");
	shapeTool.setSelectedShapeType(ShapeTool::TRIANGLE);
}

void GuiManager::OnClickCircleTool()
{
	ResetButtonImages();
	buttons["CircleTool"]->getRenderer()->setTexture("Textures/CircleTool-s.png");
	shapeTool.setSelectedShapeType(ShapeTool::CIRCLE);
}

void GuiManager::OnClickLineTool()
{
	ResetButtonImages();
	buttons["LineTool"]->getRenderer()->setTexture("Textures/LineTool-s.png");
	shapeTool.setSelectedShapeType(ShapeTool::LINE);
}

void GuiManager::OnClickColorPickerTool()
{
	ResetButtonImages();
	canDraw = false;
	tgui::ColorPicker::Ptr colorPicker = tgui::ColorPicker::create();
	colorPicker->onOkPress.connect(&GuiManager::handleOnOkayPressed, this, colorPicker);
	gui.add(colorPicker);
}

void GuiManager::handleOnOkayPressed(tgui::ColorPicker::Ptr colorPicker)
{
	tgui::Color incolor = colorPicker->getColor();
	sf::Color sfColor = TguiColorToSfColor(incolor);
	shapeTool.setSelectedColor(sfColor);
	buttons["ColorPickerTool"]->getRenderer()->setBackgroundColor(incolor);
	canDraw = true;
}

sf::Color GuiManager::TguiColorToSfColor(const tgui::Color& tguiColor)
{
	return sf::Color(
		tguiColor.getRed(),
		tguiColor.getGreen(),
		tguiColor.getBlue(),
		tguiColor.getAlpha()
	);
}

void GuiManager::ResetButtonImages()
{
	buttons["RectangleTool"]->getRenderer()->setTexture("Textures/RectangleTool.png");
	buttons["TriangleTool"]->getRenderer()->setTexture("Textures/TriangleTool.png");
	buttons["CircleTool"]->getRenderer()->setTexture("Textures/CircleTool.png");
	buttons["LineTool"]->getRenderer()->setTexture("Textures/LineTool.png");
	buttons["ColorPickerTool"]->getRenderer()->setBackgroundColor(shapeTool.GetSelectedColor());
}

