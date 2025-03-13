#ifndef SORTING_H
#define SORTING_H

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <vector>
#include <cstdlib>


#include "../sfml/graphics.h"
#include "../threading/delay.h"
#include "../gui/gui.h"

 
void bubbleSort(sf::RenderWindow& window, tgui::Gui& gui, std::vector<int>& array); 

void merge(sf::RenderWindow& window, tgui::Gui& gui, std::vector<int>& array, int left, int mid, int right);

void mergeSort(sf::RenderWindow& window, tgui::Gui& gui, std::vector<int>& array, int left, int right);

int partition(sf::RenderWindow& window, tgui::Gui& gui, std::vector<int>& array, int low, int high);

void quickSort(sf::RenderWindow& window, tgui::Gui& gui, std::vector<int>& array, int low, int high);

int maxElement(std::vector<int> array);

void randArray(std::vector<int>& array, int numElements);

#endif