#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "../sfml/graphics.h"
#include "../threading/delay.h"


void bubbleSort(sf::RenderWindow& window, std::vector<int>& array);

void merge(sf::RenderWindow& window, std::vector<int>& array, int left, int mid, int right);

void mergeSort(sf::RenderWindow& window, std::vector<int>& array, int left, int right);

int partition(sf::RenderWindow& window, std::vector<int>& array, int low, int high);

void quickSort(sf::RenderWindow& window, std::vector<int>& array, int low, int high);

int maxElement(std::vector<int> array);

std::vector<int> randArray(int numElements);

#endif