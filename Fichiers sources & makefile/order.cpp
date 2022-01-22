#include "order.h"

Order::Order(client::Client clientOrder, std::vector<Product> products) : _clientOrder(clientOrder), _products(products){
	srand(time(NULL));
	_orderNumber = rand() % 100000 + 1; //creer un numero de commande entre 1 et 10 0000
}

std::string Order::getId() const {
	return _clientOrder.getId();
}

int Order::getStatus() const {
	return _status;
}

void Order::setSatus(status stat)
{
	_status = stat;
}

void Order::displayStatus() {
	if (_status == pas_livree) {
		std::cout << "N a pas ete livree" << std::endl;
	} else if (_status == livree) {
		std::cout << "A ete livre" << std::endl;
	}
	else if (_status == en_cours) {
		std::cout << "En cours de livraison" << std::endl;
	}
}

int Order::getOrderNumber()
{
	return _orderNumber;
}

//affichage des produits du client
std::string Order::displayProducts() {
	std::string res = "";
	for (int i = 0; i < _products.size(); i++) {
		res += _products.at(i).getTitle();
		if (i != _products.size() - 1)
		{
			res += "\n";
		}
	}

	return res;
}

std::ostream& operator<<(std::ostream& os, Order& ordr) {
	os << "---Informations sur la commande---";
	os << std::endl;
	os << "Client : ";
	os << ordr.getId();
	os << std::endl;
	os << "Numero de commande: ";
	os << ordr.getOrderNumber();
	os << "Liste des produits : ";
	os << std::endl;
	os << ordr.displayProducts();
	os << std::endl;
	os << "Statut : ";
	ordr.displayStatus();
	os << std::endl;

	return os;
}