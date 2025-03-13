#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

#include "../algorithms/sorting.h"

void initTGUI(sf::RenderWindow& window, tgui::SFML_GRAPHICS::Gui& gui);

void connectButtonsToActions(sf::RenderWindow& window, tgui::Gui& gui, std::vector<int>& array);

void processEvents(sf::RenderWindow& window, tgui::Gui& gui);


#endif