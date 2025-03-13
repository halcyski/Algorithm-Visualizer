#include "graphics.h"

// drawBars : sf::RenderWindow& [Vector Int]& -> Void
// draws the corresponding bars for a given set of data points 
void drawBars(sf::RenderWindow& window, const std::vector<int>& data)
{

	// Dividing the window into equal amount of bars based on the size of data
	// TODO: add padding
	float barWidth = window.getSize().x / static_cast<float>(data.size());
	float scale = window.getSize().y / maxElement(data);

	for (size_t i = 0; i < data.size(); i++)
	{
		// Create bar corresponding to each datapoint in data
		sf::RectangleShape bar(sf::Vector2f(barWidth - 2, data[i]));
		// setting the position so that the bars expand in the x direction as i increases 
		// (or traverses the array of data)
		bar.setPosition(i * barWidth, window.getSize().y - data[i]);
		// Setting color
		bar.setFillColor(sf::Color::Cyan);
		// Drawing each bar
		window.draw(bar);
	}

}
