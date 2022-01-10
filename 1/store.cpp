#include "store.h"

Store::Store(std::string name) : _name(name) {

}

std::string Store::getName() const {
	return _name;
}