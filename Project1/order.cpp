#include "order.h"

Order::Order(client::Client id, std::vector<Product> products, bool status) : _id(id), _products(products), _status(status) {

}

std::string Order::getId() const {
	return _id.getId();
}

bool Order::getStatus() const {
	return _status;
}

void Order::displayStatus() {
	if (_status == 0) {
		std::cout << "N'a pas été livré" << std::endl;
	} else if (_status == 1) {
		std::cout << "A été livré" << std::endl;
	}
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
	os << "Liste des produits : ";
	os << std::endl;
	os << ordr.displayProducts();
	os << std::endl;
	os << "Statut : ";
	ordr.displayStatus();
	os << std::endl;

	return os;
}