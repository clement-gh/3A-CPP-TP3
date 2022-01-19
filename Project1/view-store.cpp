#include "view-store.h"

ViewStore::ViewStore(Controller& _controller) : View("Gestion du magasin"), controller(_controller)
{
	this->controller.addObserver(this);
}

void ViewStore::notify()
{
	if (this->controller.getCurrentScreen() == 1)
		this->display();
}



void ViewStore::display()
{
	
	int choice = 0;
	//do {
		clear();
		std::cout << "Menu gestion du magasin" << std::endl << std::endl;
		std::cout << "\t\t1. Affichage des produits du magasin" << std::endl; 
		std::cout << "\t\t2. Ajouter un produit au magasin" << std::endl;
		std::cout << "\t\t3. Mise a jour de la quantité d'un produit" << std::endl;
		std::cout << "\t\t4. Afficher tous les clients" << std::endl;
		std::cout << "\t\t5. Afficher toutes les commandes du magasin" << std::endl;
		std::cout << "\t\t--------------------------------------------" << std::endl;
		std::cout << "\t\t0. Retour au menu principal" << std::endl;
		std::cin.clear();
		std::cin >> choice;

		if(choice == 0){ controller.setScreen(choice); }
		else if (choice !=0 && choice<7) {
			switch (choice)
			{
			case 1: controller.displayproductsOfStore(); break;
			case 2: controller.addProductToStore(); break;
				
			
			case 3: controller.updateQuantityOfProduct(); break;
				

			case 4: controller.displayAllClient(); break;
			case 5: controller.displayAllOrder(); break;

			default:
				break;
			}


		}

		
	//} while (choice != 0);
	
	
}
