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


