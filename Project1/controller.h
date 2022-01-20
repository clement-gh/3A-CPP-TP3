#pragma once
#include "subject.h"
#include "store.h"

class Controller: public Subject//, public Store
{
private:
	int currentScreen;
	Store& _mystore = *new Store();
	std::string	_nameclient;
public:
	Controller();
	void setScreen(const int& idViews);
	int getCurrentScreen();
	std::string setLocalName();
	//menu store
	void displayproductsOfStore();
	void updateQuantityOfProduct();
	void addProductToStore();
	void displayAllClient();
	void displayAllOrder();
	void addclientNew();
	//menu order
	void confirmAOrder();
	void updateSatusOrder();
	void displayOrdersOfAClient();
	
	//menu client
	std::string getNameOfClient()const;
	void setNameOfClient();
	void delNameofClient();
	void displayClient();
	

	void addProcuctInCart();
	void delPoductToCart();
	void displayCart();
	void clearCart();
	void updateProductQuantityCart();
	void displayInfoCilent();
};