#include <SFML/Graphics.hpp>
#include <vector>

#include "algorithms/sorting.h"

// main process entry point
int main()
{
	// Temporary Window / Gui handler. 
	// TODO: Incorperate window states & TGUI buttons
	sf::RenderWindow window(sf::VideoMode(800, 600), "Algorithm Visualizer");

	// Example array
	std::vector<int> array = randArray(100);

	bubbleSort(window, array);
	// Event Loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
	return 0;

}