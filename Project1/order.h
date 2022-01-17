#include <string>
#include <vector>
#include "client.h"
#include <iostream>

#ifndef ORDER_H
#define ORDER_H
enum  status {
	livree=2 , pas_livree=0 , en_cours=1
 
 };
class Order {
	public :
		Order(client::Client id, std::vector<Product> products, int status);

		std::string getId() const;
		int getStatus() const;
		//void setSatus( status);
		std::string displayProducts();

	private :
		client::Client _id;
		std::vector<Product> _products;
	int _status =  status::pas_livree ; // 0 = pas livrée et 1 = livrée
};

std::ostream& operator<<(std::ostream& os, Order& ordr);

#endif