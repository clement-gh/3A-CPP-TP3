#include "controller.h"
#include <limits>
Controller::Controller() : currentScreen(0)
{


}
void Controller::setScreen(const int& idViews)
{
	if (idViews >= 0 && idViews <= 9)
	{
		this->currentScreen = idViews;
		this->notify();
	}
}

int Controller::getCurrentScreen()
{
	return this->currentScreen;
}

std::string Controller::setNameOfClient()
{
	std::string name;
	std::cout << "Saisisez le Nom du client" << std::endl;
	std::cin >> name;
	return name;
}

void Controller::displayproductsOfStore()
{
	_mystore.toStringProducts();
	
}

void Controller::updateQuantityOfProduct()
{
	std::string nameproduct;
	std::cout << "Saisisez un nom de produit:" << std::endl;
	std::cin >> nameproduct;
	int quantity = 0;
	std::cout << "Saisisez une quantité:" << std::endl;
	std::cin >> quantity;



}

void Controller::addProductToStore()
{
	std::string title, description;
	
	double price = 0;
	int quantity = 0;
	std::cout << "Entrez le nom du produit:" << std::endl;
	std::cin >> title; //getline permet de rentrer plusieurs chines de caractères avec des espaces
	std::cout << "Entrez la description du produit:" << std::endl;
	std::cin >> description;
	std::cout << "Entrez le prix du produit:" << std::endl;
	std::cin >> price;
	std::cout << "Entrez la quantite du produit:" << std::endl;
	std::cin >> quantity;
	Product prdct(title, description, price, quantity);
	_mystore.addProduct(prdct);
}

void Controller::displayAllClient()
{
	_mystore.toStringClients();
}

void Controller::displayAllOrder()
{
	_mystore.toStringorders();
}

void Controller::confirmAOrder()
{
	std::string name = this->setNameOfClient();

	_mystore.confirmOrder(name);

}

void Controller::updateSatusOrder()
{
	int orderNumber, x;
	status stat;
	std::cout << "Entrez le numero de commande de la commande a modifier: " << std::endl; //fonction orderNumerIsValid inexistante
	std::cin >> orderNumber;
	do {
		std::cout << "\t\t   Liste des status possibles" << std::endl;
		std::cout << "\t\t1. Pas livree " << std::endl;
		std::cout << "\t\t2. En cours de livraison" << std::endl;
		std::cout << "\t\t3. Livree" << std::endl;
		std::cout << "\t\t--------------------------------------------" << std::endl;
		std::cout << "\t\t0. Annuler "<<std::endl;
		std::cout << "Entrez un status ou 0 pour revenir en arrière" << std::endl;
		std::cin >> x;
		switch (x)
		{
		case 0: break;
		case 1: stat=pas_livree; break;
		case 2: stat=en_cours; break;
		case 3:stat=livree; break;
		default:
			break;
		}

	} while (x != 1 && x != 2 && x != 3);
	_mystore.updateStatusOfOrder(stat, orderNumber);
}


void Controller::displayOrdersOfAClient()
{
	std::string name = this->setNameOfClient();
	_mystore.toStringAllOrdersOfClient(name);
}


