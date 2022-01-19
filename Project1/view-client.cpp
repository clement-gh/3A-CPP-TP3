#include "view-client.h"
#include <iostream>

ViewClient::ViewClient(Controller& _controller): View("Gestion des clients"), controller(_controller)
{
	this->controller.addObserver(this);
}

void ViewClient::notify()
{
	if (this->controller.getCurrentScreen() == 2)
		this->display();
}

void ViewClient::display()
{
	int choice = 0;
	//while (choice =!0) {

		
			View::display();
		clear();
		std::cout << "Menu gestion des clients" << std::endl << std::endl;
		std::cout << "\t\t1. Ajout produit dans le panier" << std::endl;
		std::cout << "\t\t2. Supression d'un produit du panier" << std::endl;
		std::cout << "\t\t3. Affichage du panier" << std::endl;
		std::cout << "\t\t4. Vider le panier" << std::endl;
		std::cout << "\t\t5. Modifier la quantité d'un prodduit du panier" << std::endl;
		std::cout << "\t\t6. Afficher les informations d'un client" << std::endl;
		std::cout << "\t\t--------------------------------------------" << std::endl;
		std::cout << "\t\t0. Retour au menu principal" << std::endl;
		std::cin.clear();
		std::cin >> choice;
		
			
	
	controller.setScreen(choice);
}

