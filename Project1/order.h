#include <string>
#include <vector>
#include "client.h"
#include <iostream>

#ifndef ORDER_H
#define ORDER_H

class Order {
	public :
		Order(client::Client id, std::vector<Product> products, bool status);

		std::string getId() const;
		bool getStatus() const;

		std::string displayProducts();

	private :
		client::Client _id;
		std::vector<Product> _products;
		bool _status; // 0 = pas livrée et 1 = livrée
};

std::ostream& operator<<(std::ostream& os, Order& ordr);

#endif