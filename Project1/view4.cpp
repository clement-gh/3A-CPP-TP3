#include "view4.h"

View4::View4(Controller& _controller): View("Liste des produits du magasin"), controller(_controller)
{
	this->controller.addObserver(this);
}

void View4::notify()
{
	if (this->controller.getCurrentScreen() == 4)
		this->display();
}

void View4::display()
{
	

	int choice = 0;
	do {
		clear();
		View::display();
	
		std::cout << "\t\t--------------------------------------------" << std::endl;
		//std::cout << "\t\t9. Retour au menu précedent" << std::endl;
		std::cout << "\t\t0. Retour au menu principal" << std::endl;
		std::cout << std::endl;
		std::cin.clear();
		std::cin >> choice;

	
		

	} while (choice != 0 && choice !=1);

	controller.setScreen(choice);
}
	

