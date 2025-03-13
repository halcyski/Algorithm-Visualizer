#include "gui.h"

// initTGUI : sf::RenderWindow& tgui::Gui& -> Void
// Initializes GUI elements, assigning positions, sizes, and defaults for all of them.
void initTGUI(sf::RenderWindow& window, tgui::Gui& gui)
{	
	// Instantiate a combobox element, set pos, size, add items (or algorithms), and set a default.
	auto algorithmDropdown = tgui::ComboBox::create();
	algorithmDropdown->setPosition("10%", "85%");
	algorithmDropdown->setSize("15%", "10%");
	algorithmDropdown->addItem("Bubble Sort");
	algorithmDropdown->addItem("Merge Sort");
	algorithmDropdown->addItem("Quick Sort");
	// algorithmDropdown->addItem("...")
	// add more items when more sorting algorithms are added.
	algorithmDropdown->setSelectedItem("Bubble Sort"); // default item
	gui.add(algorithmDropdown, "algorithmDropdown");

	// Instantiate a button element, set pos and size.
	auto randomizeButton = tgui::Button::create();
	randomizeButton->setPosition("30%", "85%");
	randomizeButton->setSize("15%", "10%");
	gui.add(randomizeButton, "randomizeButton");

	// Instantiate a slider element, set pos, size, max, min, and default value.
	auto numElementsSlider = tgui::Slider::create();
	numElementsSlider->setPosition("50%", "85%");
	numElementsSlider->setSize("15%", "3%");
	numElementsSlider->setMaximum(250); // Max array size 
	numElementsSlider->setMinimum(10); // Min array size
	numElementsSlider->setValue(100); // defualt array size
	gui.add(numElementsSlider, "numElementsSlider");

	// Instantiate a button element, set pos and size.
	auto sortButton = tgui::Button::create();
	sortButton->setPosition("75%", "85%");
	sortButton->setSize("15%", "10%");
	gui.add(sortButton, "sortButton");
} 


void connectButtonsToActions(sf::RenderWindow& window, tgui::Gui& gui, std::vector<int>& array)
{
	auto algorithmDropdown = gui.get<tgui::ComboBox>("algorithmDropdown");
	auto randomizeButton = gui.get<tgui::Button>("randomizeButton");
	auto numElementsSlider = gui.get<tgui::Slider>("numElementsSlider");
	auto sortButton = gui.get<tgui::Button>("sortButton");
	
	// Handler for when randomize is clicked, assigns new values to the array and displays it.
	randomizeButton->onClick([&]()
		{
			int numElements = static_cast<int>(numElementsSlider->getValue());
			randArray(array, numElements);
		});

	sortButton->onClick([&]() {
		std::string currAlgorithm = algorithmDropdown->getSelectedItem().toStdString(); 
		// Change to map w/ switch case
		if (currAlgorithm == "Bubble Sort")
		{ 
			bubbleSort(window, gui, array);
		}
		else if (currAlgorithm == "Merge Sort")
		{
			mergeSort(window, gui, array, 0, array.size() - 1);
		}
		else if (currAlgorithm == "Quick Sort")
		{
			quickSort(window, gui, array, 0, array.size() - 1);
		}
		});

}

void processEvents(sf::RenderWindow& window, tgui::Gui& gui) 
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		gui.handleEvent(event);

		/*if (event.type == sf::Event::Closed)
		{
			window.close();
		}*/

	}
}