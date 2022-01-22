#include <iostream>
#include "order.h"
#include "client.h"
#include "product.h"

int main () {
	client::Client c1("Clement", "Ghys");

	Product p1("PS4", "Console de jeu de marque Sony", 249.99, 1);

	Product p2("Iphone 13", "Smartphone de la marque Apple", 909, 1);

	c1.addProductToCart(p1);

	c1.addProductToCart(p2);

	//Afficher les informations du client (identifiants + produits dans le panier)
	std::cout << c1 << std::endl;

	Order myOrder(c1,{p1,p2});


	myOrder.displayStatus();
	myOrder.setSatus(status::en_cours);
	
	myOrder.displayStatus();

	std::cout << myOrder.getOrderNumber() << std::endl;
	//Afficher les produits de la commande
	//std::cout << myOrder << std::endl; 

	std::cout << "---Fin du programme---" << std::endl;

	return 0;
}