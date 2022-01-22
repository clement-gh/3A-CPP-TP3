#include "view.h"
#include <cstdlib>
#include <iostream>

/**
 * Constructor
 * @param _title: Title of the view
 */
View::View(const std::string& _title)
	:title(_title)
{

}

/**
 * Clears console
 */
void View::clear() const
{
	system("CLS");
}

void View::waiting() const
{
	int wait;
	do {
		std::cout << "Appuiez sur 0 puis sur Entrer pour revenir au menu." << std::endl;
		std::cin >> wait;

	} while (wait != 0);
	clear();
}

/**
 * Displays the view
 */
void View::display() const
{
	std::cout << title << std::endl << std::endl;
}
