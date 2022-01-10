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