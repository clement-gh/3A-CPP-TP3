#include "product.h"

Product::Product(std::string title, std::string description, double price, int quantity) : _title(title), _description(description), _price(price), _quantity(quantity) {

}

std::string Product::getTitle() const {
	return _title;
}

std::string Product::getDescription() const {
	return _description;
}

double Product::getPrice() const {
	return _price;
}

int Product::getQuantity() const {
	return _quantity;
}

std::string Product::toString() const {
	std::string res ="";
	res += "Produit : ";
	res += _title;
	res += "\n";
	res += "Description : " ;
	res += _description;
	res += "\n";
	res += "Prix : ";
	res += std::to_string(this->getPrice());
	res += " €";
	res += "\n";
	res += "Quantité : ";
	res += std::to_string(this->getQuantity());
	res += "\n";

	return res;
}

void Product::updateQuantity(int quantity) {
	_quantity = quantity;
}

//surcharge de <<
std::ostream& operator<<(std::ostream& res, Product& prdct)
{
	res << "";
	res << "Produit : ";
	res << prdct.getTitle();
	res << std::endl;
	res << "Description : ";
	res << prdct.getDescription();
	res << std::endl;
	res<< "Prix : ";
	res << prdct.getPrice();
	res << " Euros";
	res << std::endl;;
	res << "Quantite : ";
	res << prdct.getQuantity();
	res << std::endl;

	return res;
}