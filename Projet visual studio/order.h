#include <string>
#include <vector>
#include "client.h"
#include <iostream>


#ifndef ORDER_H
#define ORDER_H
enum status {
	 pas_livree=0, en_cours=1, livree=2
 
 };
class Order {
	public :
		Order(client::Client clientOrder, std::vector<Product> products);

		std::string getId() const;
		int getStatus() const;
		void setSatus( status stat);
		std::string displayProducts();
		void displayStatus();
		int getOrderNumber();

	private :
		client::Client _clientOrder;
		std::vector<Product> _products;
	status _status = pas_livree; 
	int _orderNumber =0;
};

std::ostream& operator<<(std::ostream& os, Order& ordr);

#endif