#include <string>
#include <vector>
#include "product.h"

#ifndef STORE_H
#define STORE_H

class Store {
	public :
		Store(std::string name);

		std::string getName() const;

		void updateProduct();

		void addProduct(Product prdct);

		std::string toString();

		void findProduct();

	private :
		std::string _name;

		std::vector<Product> _products;
};

#endif