#include <SFML/Graphics.hpp>
#include <vector>

#include "algorithms/sorting.h"
#include "./gui/gui.h"


// main process entry point
int main()
{
	// Temporary Window / Gui handler. 
	// TODO: Incorperate window states & TGUI buttons
	sf::RenderWindow window(sf::VideoMode(800, 600), "Algorithm Visualizer");
	tgui::Gui gui(window);
	initTGUI(window, gui);

	// Array to be used for sorting.
	std::vector<int> array; 
	connectButtonsToActions(window, gui, array); 

	// Event Loop
	while (window.isOpen()) 
	{
		processEvents(window, gui);
		window.clear();

		if (!array.empty()) 
		{
			drawBars(window, array);
		}

		gui.draw();
		window.display();
	}

	return 0;

}


