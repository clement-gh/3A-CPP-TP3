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

		void toStringProducts();
		void toStringClients();
		void findProduct(std::string nameOfProduct);
		void findClient(std::string nameOfClient);
		void updateQuantity(std::string nameOfProduct, int quantity);
		void addClient(client::Client& client);


		void addProductToCart(Product product, client::Client client);
		void delProductToCart(Product product, client::Client client);
		void updateQuantityOfProduct(Product product, client::Client client ,int quantity);
		
	private :
		std::string _name;
		std::vector <client::Client> _clients;
		std::vector<Product> _products;
};


template <typename T > std::string display(const std::vector<T>  elems){

	std::string res = "";

	for (int i = 0; i < elems.size(); i++) {
		res += elems.at(i).toString();
		if (i != elems.size() - 1)
		{
			res += "\n";
		}
	}

	return res;

};

#endif
