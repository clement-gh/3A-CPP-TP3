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