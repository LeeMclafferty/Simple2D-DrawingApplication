#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "DrawingApp.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Drawing");
    tgui::Gui gui{ window };
    ShapeTool shapeTool;
	GuiManager guiManager(window, gui, shapeTool);
	DrawingApp drawingApp(window, guiManager, shapeTool);

	drawingApp.MainLoop();
    
    return 0;
}
