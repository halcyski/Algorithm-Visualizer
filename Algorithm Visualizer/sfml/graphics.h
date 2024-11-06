#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>

#include "../algorithms/sorting.h"

void drawBars(sf::RenderWindow& window, const std::vector<int>& data);

#endif 