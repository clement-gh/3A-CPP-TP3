#pragma once
#include <string>
#include <vector>
#include "product.h"
#include <ostream>

namespace client {
	class Client
	{
	private:
		std::string _firstname;
		std::string _surname;
		std::vector<Product> _cart = {};
		std::string _id;

	public:
		Client(std::string firstname, std::string surname);
		std::string getFirstname()const;
		std::string getSurname()const;
		std::string getId()const;
		void initializeId();
		void addProductToCart(Product prdct);
		void clearCart();
		void setQuantity(Product prdct, int quantity);
		void delProductToCart(Product prdct);
		std::string toString();
	};
	
	std::ostream& operator<<(std::ostream& os, Client& c);
	
};