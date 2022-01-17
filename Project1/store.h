#include <string>
#include <vector>
#include "product.h"
#include "client.h"

#ifndef STORE_H
#define STORE_H

class Store {
	public :
		Store(std::string name);

		std::string getName() const;

		

		void addProduct(Product& prdct);

		std::string toString();

		void findProduct(std::string nameOfProduct);

		void updateQuantity(std::string nameOfProduct, int quantity);
		void addClient(client::Client& client);

	private :
		std::string _name;
		std::vector <client::Client> _clients;
		std::vector<Product> _products;
};

#endif