#include "store.h"

Store::Store(std::string name)  {

}

Store::Store():_name("mystore")
{
}

std::string Store::getName() const {
	return _name;
}

void Store::addProduct(Product& prdct) {
	_products.push_back(prdct);
}

void Store::toStringProducts() { //affiche tout les produits du magasin
	std::cout << _products<< std::endl;
	
}

void Store::toStringClients()
{
	
	std::cout << _clients << std::endl;
}

void Store::toStringorders()
{
	std::cout << _orders << std::endl;
}

Product Store::findProduct(std::string nameOfProduct, std::vector<Product> list) {
	Product res("","",0,0);
	for(int i=0; i < list.size(); i++) {
		if (list.at(i).getTitle() == nameOfProduct) {
			//std::cout << "Produit trouvé\n";
			//std::cout << _products.at(i).toString();
			res = list.at(i);
			return list.at(i);
		}

	}
	if (res.getTitle() != nameOfProduct) {
		std::cout << "ce produit n'existe pas " << std::endl;
		return res;
	}
	
}

client::Client& Store::findClient(std::string nameOfClient)
{
	client::Client res("", "");
	
	for (int i = 0; i < _clients.size(); i++) {
		if ((_clients.at(i).getSurname() == nameOfClient) || (_clients.at(i).getId() == nameOfClient)) {
			//std::cout << "Client trouvé\n";
			//std::cout << _clients.at(i).toString();
			res = _clients.at(i);
			return  _clients.at(i);
		}

	}
	if ((res.getSurname() != nameOfClient) || (res.getId() != nameOfClient)) {
		std::cout << "Aucun résultat, client non trouvé" << std::endl;
		
	}
	
}

void Store::updateQuantityToStore(std::string nameOfProduct, int quantity) {
	Product res("","",0,0);
	for(int i=0; i <_products.size(); i++) {
		if (_products.at(i).getTitle() == nameOfProduct) {
			_products.at(i).updateQuantity(quantity);
			res = _products.at(i);
			
		}

	}
	if (res.getTitle() != nameOfProduct) {
	std::cout << "Erreur ! \n";
	}
}

void Store::addClient(client::Client client) // ajout d'un client dans la liste de client du magasin
{
	_clients.push_back(client);
}

void Store::addProductToCart(std::string nameclient, std::string nameproduct, int quantity)
{
	if(verifquantity(nameproduct,quantity))
	findClient(nameclient).addProductToCart(findProduct(nameproduct, _products));  //la fonction find retourne une reference vers un client donc on auquel on ajoute le produit dans le panier
}

void Store::delProductToCart(std::string nameclient, std::string nameproduct)
{

	findClient(nameclient).delProductToCart(findProduct(nameproduct, _products));
}

void Store::updateQuantityToCart(std::string nameclient ,std::string nameproduct, int quantity)
{
	if (verifquantity(nameproduct, quantity)) {
		findProduct(nameproduct,findClient(nameclient).getCart()).updateQuantity(quantity);
	}
}


void Store::updateStatusOfOrder(status stat, int orderNumber)
{
	for (int i = 0; i < _orders.size(); i++) {
		if (_orders.at(i).getOrderNumber() == orderNumber ) {
			_orders.at(i).setSatus(stat);
		
		}

	}

}



void Store::confirmOrder(std::string nameclient)
{
	client::Client& client = findClient(nameclient);
	if (client.getCart().empty() == false) {

		for (int i = 0; i < _products.size(); i++) {
			for (int j = 0; j < client.getCart().size(); j++) {
				if (_products.at(i).getTitle() == client.getCart().at(j).getTitle()) {
					_products.at(i).updateQuantity((_products.at(i).getQuantity()) - (client.getCart().at(j).getQuantity()));
				}
			}

		}
		Order order(client, client.getCart());
		client.clearCart();

		_orders.push_back(order);
		std::cout << "Commande validée" << std::endl;
	}
	else { std::cout << "Le panier de "<< client.getFirstname()<< " " << client.getSurname() << "est vide." << std::endl; }
}

void Store::toStringAllOrdersOfClient(std::string nameclient)
{
	client::Client& client = findClient(nameclient);
	std::cout << client.getFirstname() << " " << client.getSurname() << "a comme commandes: " <<std::endl;
	for (int i = 0; i < _orders.size(); i++) {
		
		if (_orders.at(i).getId() == client.getId()) {
			std::cout <<_orders.at(i);

		}

	}
}

bool Store::verifquantity(std::string nameproduct, int quantity)
{
	//verifie que le produit selectionné est en quantité suffisante ou egale a la quantité passée en paramètre
	if (findProduct(nameproduct, _products).getQuantity() == 0)
		std::cout << "Il n y a plus de " << nameproduct << " en stock." << std::endl;
	else if (findProduct(nameproduct, _products).getQuantity() < quantity) {
		std::cout << "il y a seulement " << findProduct(nameproduct, _products).getQuantity() << " " << nameproduct;
		std::cout << "dans le magasin veuillez selectioner un quantité inferieure." << std::endl;
	}
	if (findProduct(nameproduct, _products).getQuantity() != 0 && findProduct(nameproduct, _products).getQuantity() >= quantity)
		return true;
	else
		return false;
}


