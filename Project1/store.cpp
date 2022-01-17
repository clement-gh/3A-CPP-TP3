#include "store.h"

Store::Store(std::string name) : _name(name) {

}

std::string Store::getName() const {
	return _name;
}

void Store::addProduct(Product& prdct) {
	_products.push_back(prdct);
}

std::string Store::toString() { //affiche tout les produits du magasin
	std::string res = "";
	for(int i=0; i<_products.size(); i++) {
		res += _products.at(i).toString();
		if (i != _products.size()-1)
		{
			res += "\n";
		}
	}

	return res;
}

void Store::findProduct(std::string nameOfProduct) {
	Product res("","",0,0);
	for(int i=0; i <_products.size(); i++) {
		if (_products.at(i).getTitle() == nameOfProduct) {
			std::cout << "Produit trouvé\n";
			std::cout << _products.at(i).toString();
			res = _products.at(i);
		}

	}
	if (res.getTitle() != nameOfProduct) {
		std::cout << "Aucun résultat\n";
	}
}

void Store::updateQuantity(std::string nameOfProduct, int quantity) {
	Product res("","",0,0);
	for(int i=0; i <_products.size(); i++) {
		if (_products.at(i).getTitle() == nameOfProduct) {
			_products.at(i).updateQuantity(quantity);
			res = _products.at(i);
		}

	}
	if (res.getTitle() != nameOfProduct) {
	std::cout << "Erreur ! \n";
	}
}

void Store::addClient(client::Client& client) // ajout d'un client dans la liste de client du magasin
{
	_clients.push_back(client);
}
