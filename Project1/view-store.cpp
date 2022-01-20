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
void ViewStore::waiting() {
	int wait;
	do {
		std::cout << "Appuiez sur 0 puis sur Entrer pour revenir au menu." << std::endl;
		std::cin >> wait;
		
	} while (wait != 0);
	clear();
}


void ViewStore::display()
{
	
	int choice = 0;
	
	//while (choice !=2  /* && choice != 2 && choice != 6 /* && choice != 7 /* && choice != 8 && choice != 0 */) {
	do{
		clear();
		View::display();
		std::cout << "\t\t1. Affichage des produits du magasin" << std::endl;
		std::cout << "\t\t2. Ajouter un produit au magasin" << std::endl;
		std::cout << "\t\t3. Mise a jour de la quantite d'un produit" << std::endl;
		std::cout << "\t\t4. Afficher tous les clients" << std::endl;
		std::cout << "\t\t5. Afficher toutes les commandes du magasin" << std::endl;

		std::cout << "\t\t--------------------------------------------" << std::endl;
		std::cout << "\t\t0. Retour au menu principal" << std::endl;
		std::cout << std::endl;
		std::cin.clear();
		std::cin >> choice;
		
		switch (choice)
		{
		case 0: controller.setScreen(choice); break;
		case 1: controller.displayproductsOfStore(); waiting(); break;
		case 2: controller.addProductToStore(); break;
		case 3: controller.updateQuantityOfProduct(); break;
		case 4: controller.displayAllClient(); waiting(); break;
		case 5: controller.displayAllOrder(); waiting(); break;


		default:
			break;
		}
	} while (choice != 0);
	
}
