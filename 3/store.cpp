#include "store.h"

Store::Store(std::string name) : _name(name) {

}

std::string Store::getName() const {
	return _name;
}

void Store::addProduct(Product prdct) {
	_products.push_back(prdct);
}

std::string Store::toString() {
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

void Store::findProduct() {
	Product res("","",0,0);
	std::cout << "Entrez un produit : ";
	std::string nameOfProduct;
	std::cin >> nameOfProduct;
	for(int i=0; i <_products.size(); i++) {
		if (_products.at(i).getTitle() == nameOfProduct) {
			std::cout << _products.at(i).toString();
			res = _products.at(i);
		}

	}
	if (res.getTitle() != nameOfProduct) {
		std::cout << "Aucun résultat\n";
	}
}