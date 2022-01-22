#include <iostream>
#include "product.h"

int main ()
{
	//création d'un livre
	Product p1("PS4", "Console de jeu de marque Sony", 249.99, 10);
	
	//affichage des info du produit
	std::cout << "Informations du produit : " <<std::endl;
	std::cout << "Produit : " << p1.getTitle() << std::endl;
	std::cout << "Description : " << p1.getDescription() << std::endl;
	std::cout << "Prix : " << p1.getPrice() << " €" << std::endl;
	std::cout << "Quatité : " << p1.getQuantity() << std::endl;

	std::cout << p1 << std::endl;
	//Modification de la quantité
	p1.updateQuantity(9);
	std::cout << "La nouvelle quantité est de : " << p1.getQuantity() << std::endl;

	std::cout << "Fin du programme" << std::endl;
	
	return 0;
}