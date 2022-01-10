#include "product.h"

Product::Product(std::string title, std::string description, float price, int quantity) : _title(title), _description(description), _price(price), _quantity(quantity) {

}

std::string Product::getTitle() const {
	return _title;
}

std::string Product::getDescription() const {
	return _description;
}

float Product::getPrice() const {
	return _price;
}

int Product::getQuantity() const {
	return _quantity;
}

void Product::updateQuantity(int quantity) {
	_quantity = quantity;
}

std::ostream& operator<<(std::ostream& os, Product& prdct) {
	os << "Informations du produit : ";
	os << std::endl;
	os << "Produit : ";
	os << prdct.getTitle();
	os << std::endl;
	os << "Description : " ;
	os << prdct.getDescription();
	os << std::endl;
	os << "Prix : ";
	os << prdct.getPrice();
	os << " €";
	os << std::endl;
	os << "Quantité : ";
	os << prdct.getQuantity();

	return os;
}