#include <iostream>
#include "store.h"

int main () {
	Store store("EasyStore");

	std::cout << "Nom du magasin : " << store.getName() << std::endl;

	std::cout << "Fin du programme" << std::endl;

	return 0;
}
