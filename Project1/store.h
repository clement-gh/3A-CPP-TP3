#include <string>
#include <vector>
#include "product.h"
#include "client.h"
#include "order.h"
#include <typeinfo>

#ifndef STORE_H
#define STORE_H

class Store
{
	public :
		Store(std::string name);
		Store();
		std::string getName() const;

		
		//magasin
		//add
		void addProduct(Product& prdct);
		void addClient(client::Client& client);
		//affichage
		void toStringProducts();
		void toStringClients();
		void toStringorders(); //question 7c
		
		bool verifquantity(std::string nameproduct, int quantity);
		void updateQuantityToStore(std::string nameOfProduct, int quantity);
	

		//find
		Product findProduct(std::string nameOfProduct, std::vector<Product> list);
		client::Client& findClient(std::string nameOfClient);

		//panier
		void addProductToCart( std::string client, std::string nameproduct, int quantity);
		void delProductToCart(std::string client, std::string );
		void updateQuantityToCart(std::string nameclient, std::string nameproduct, int quantity);
		
		//order
		void updateStatusOfOrder(status stat, int orderNumber);
		void confirmOrder(std::string nameclient);
		void toStringAllOrdersOfClient(std::string nameclient);
	

	private :
		std::string _name;
		std::vector <client::Client> _clients;
		std::vector<Product> _products;
		std::vector<Order> _orders;
};

//evite de faire 3 surcharges
template <typename T > std::ostream &operator<<(std::ostream& res, std::vector<T>&  elems ){

	for (int i = 0; i < elems.size(); i++) {
		res << elems.at(i);
		if (i != elems.size() - 1)
		{
			res << std::endl;
		}
	}

	return res;
};


#endif

