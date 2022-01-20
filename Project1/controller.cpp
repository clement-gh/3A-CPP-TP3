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

std::string Controller::setLocalName()
{
	std::string name;
	std::cout << "Saisisez le Nom du client" << std::endl;
	std::cin >> name;
	return name;
}

std::string Controller::getNameOfClient()const
{
	return _nameclient;
}

void Controller::setNameOfClient()
{

	std::cout << "Saisisez le Nom du client" << std::endl;
	std::cin >> _nameclient;

	if (_mystore.checkClientExist(_nameclient) == false) {
		std::cout << "Client Introuvable " << std::endl;
		std::cout << "1. Rentrer un nouveau client" << std::endl;
		std::cout << "0. retour au menu principal" << std::endl;
		int x;
		do {
			std::cin >> x;
			if(x==0)
			this->setScreen(x);
			if(x==1){ this->setScreen(2); }

		} while (x >1 || x<0);
	}
	
}

void Controller::delNameofClient()
{
	_nameclient = "";
}

void Controller::displayClient()
{
	std::cout << "ID client:" << _mystore.findClient(_nameclient).getId() << std::endl;
}



void Controller::addProcuctInCart(){
	int quantity;
	std::string product;
	std::cout << "Entrez un nom de produit a ajouter au panier:" << std::endl;
	std::cin >> product;
	std::cout << "Entrez une quantite:" << std::endl;
	std::cin >> quantity;
	_mystore.addProductToCart(_nameclient, product, quantity);
}

void Controller::delPoductToCart()
{
	std::string product;
	std::cout << "Entrez un nom de produit a ajouter au panier:" << std::endl;
	std::cin >> product;
	_mystore.delProductToCart(_nameclient, product);
}

void Controller::displayCart()
{
	std::cout << "Produits dans le panier:" << std::endl;
	_mystore.findClient(_nameclient).toString();

}

void Controller::clearCart()
{
	_mystore.findClient(_nameclient).clearCart();
	std::cout << "Panier vide !" << std::endl;
}

void Controller::updateProductQuantityCart()
{
	int quantity;
	std::string product;
	std::cout << "Entrez un nom de produit a ajouter au panier:" << std::endl;
	std::cin >> product;
	std::cout << "Entrez une quantite:" << std::endl;
	std::cin >> quantity;
	_mystore.updateQuantityToCart(_nameclient,product,quantity );
}

void Controller::displayproductsOfStore()
{
	std::cout << "Liste des produits du magasin: " << std::endl;
	_mystore.toStringProducts();
	
}

void Controller::updateQuantityOfProduct()
{

	std::string nameproduct = this->setLocalName();
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
	std::cin >> title; 
	std::cout << "Entrez la description du produit:" << std::endl;
	std::cin >> description; //ne pas entrer d'espaces sinon plante
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
	 std::string name = this->setLocalName();

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
	std::string name = this->setLocalName();
	_mystore.toStringAllOrdersOfClient(name);
}

void Controller::displayInfoCilent()
{
	std::cout << _mystore.findClient(_nameclient)<<std::endl;
}

void Controller::addclientNew()
{
	std::string firstname;
	std::string surname = this->setLocalName();
	std::cout << "Saisisez le prenom du client" << std::endl;
	std::cin >> firstname;
	_mystore.addClient(client::Client(firstname, surname));

}


