#include <iostream>
#include "viewmenu.h"

ViewMenu::ViewMenu(const std::string& _title, Controller* _controller): View(_title)
{
	this->controller = _controller;
	this->controller->addObserver(this);
}

void ViewMenu::notify()
{
	if (this->controller->getCurrentScreen() == 0)
		this->display();
}

void ViewMenu::display()
{
	int choice = 0;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 9)
	{
		this->clear();
		std::cout << "Menu Principal" << std::endl << std::endl;
		std::cout << "\t\t1. Menu gestion du magasin" << std::endl;
		std::cout << "\t\t2. Menu gestion des clients" << std::endl;
		std::cout << "\t\t3. Menu gestion des commandes" << std::endl;
		//::cout << "\t\t4. Gestion des fichiers" << std::endl;
		std::cout << "\t\t--------------------------------------------" << std::endl;
		std::cout << "\t\t9. Quitter" << std::endl;
		std::cin >> choice;
	}
	this->controller->setScreen(choice);
}

