#include <iostream>
#include <string>

class Product {
	public :
		Product(std::string title, std::string description, float price, int quantity);

		std::string getTitle() const;
		std::string getDescription() const;
		float getPrice() const;
		int getQuantity() const;

		void updateQuantity(int quantity);

	private :
		std::string _title;
		std::string _description;
		float _price;

		int _quantity;
};

std::ostream& operator<<(std::ostream& os, Product& prdct);

