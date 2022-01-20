#include "view-order.h"

ViewOrder::ViewOrder(Controller& _controller) : View("Gestion des commandes"), controller(_controller)
{
	this->controller.addObserver(this);
}

void ViewOrder::notify()
{

	if (this->controller.getCurrentScreen() == 3)
		this->display();
}


void ViewOrder::display()
{
	int choice = 0;
	do {
		clear();
		View::display();
		std::cout << "\t\t1. Confirmer une commande" << std::endl;
		std::cout << "\t\t2. Modifier le status d'une commande" << std::endl;
		std::cout << "\t\t3. Mise a jour de la quantite d'un produit" << std::endl;
		

		std::cout << "\t\t--------------------------------------------" << std::endl;
		std::cout << "\t\t0. Retour au menu principal" << std::endl;
		std::cout << std::endl;
		std::cin.clear();
		std::cin >> choice;

		switch (choice)
		{
		case 0: controller.setScreen(choice); break;
		case 1: controller.confirmAOrder() ; break;
		case 2: controller.updateSatusOrder(); break;
		case 3: controller.displayOrdersOfAClient(); waiting(); break;
	
		default:
			break;
		}
	} while (choice != 0);

}





