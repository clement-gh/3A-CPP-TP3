#include <string>

class Store {
	public :
		Store(std::string name);

		std::string getName() const;
	private :
		std::string _name;
};