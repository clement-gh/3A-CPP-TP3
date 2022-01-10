#include <iostream>
#include "store.h"
#include "product.h"

int main () {
	Store store("EasyStore");

	std::cout << "Nom du magasin : " << store.getName() << std::endl;

	Product p1("PS4", "Console de jeu de marque Sony", 249.99, 10);

	Product p2("Iphone 13", "Smartphone de la marque Apple", 909, 9);

	store.addProduct(p1);

	store.addProduct(p2);

	std::cout << store.toString() << std::endl; 

	//Pour afficher p1 uniquement
	//std::cout << p1.toString() << std::endl;

	std::cout << "Fin du programme" << std::endl;

	return 0;
}
