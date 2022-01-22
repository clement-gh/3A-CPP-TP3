#include <iostream>
#include <string>

#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
	public :
		Product(std::string title, std::string description, double price, int quantity);

		std::string getTitle() const;
		std::string getDescription() const;
		double getPrice() const;
		int getQuantity() const;

		void updateQuantity(int quantity);
		std::string toString() const;

	private :
		std::string _title;
		std::string _description;
		double _price;
		int _quantity;
};

std::ostream& operator<<(std::ostream& res, Product& prdct);

#endif