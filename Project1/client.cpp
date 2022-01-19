#include "client.h"

client::Client::Client(std::string firstname, std::string surname) : _firstname(firstname), _surname(surname) 
{
	this->initializeId();
}

std::string client::Client::getFirstname()const
{
	return _firstname ;
}

std::string client::Client::getSurname()const
{
	return _surname;
}

std::string client::Client::getId() const
{
	return _id;
}

std::vector<Product> client::Client::getCart() const
{
	return _cart;
}

void client::Client::initializeId()
{
	std::string firstChar = _firstname.substr(0, 1); //permet d'avoir id du type cghys à partir de clement en prénom et ghys en nom
	_id = firstChar + _surname;
}

void client::Client::addProductToCart(Product prdct)
{
	_cart.push_back(prdct);

}

void client::Client::clearCart()
{
	_cart.clear();
}

void client::Client::setQuantity(Product prdct, int quantity)
{
	for (auto i = 0; i != (_cart).size(); i++) {
		if (prdct.getTitle() == _cart[i].getTitle()) {
			_cart.at(i).updateQuantity(quantity);
		}
	}
}

void client::Client::delProductToCart(Product prdct)
{
	for (auto i = _cart.begin(); i != _cart.end(); i++) {

		if (prdct.getTitle() == i->getTitle()) {
			
			_cart.erase(i);
		}
	}
}

std::ostream& client::operator<<(std::ostream& os, Client& c)
{
	os << "---Informations sur le client---";
	os << std::endl;
	os << c.getFirstname();
	os << ", ";
	os << c.getSurname();
	os << ", ";
	os << c.getId();
	os << std::endl;
	os << "---Produits dans le panier---";
	os << std::endl;
	os << c.toString();

	return os;
}

//affichage des produits du client
std::string client::Client::toString() {
	std::string res = "";
	for (int i = 0; i < _cart.size(); i++) {
		res += _cart.at(i).toString();
		if (i != _cart.size() - 1)
		{
			res += "\n";
		}
	}

	return res;
}