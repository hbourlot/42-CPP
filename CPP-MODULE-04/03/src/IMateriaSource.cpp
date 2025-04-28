#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() {

	std::cout << "IMateriaSource (default constructor)" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource& other) {
	
	*this = other;
	std::cout << "IMateriaSource (copy constructor)" << std::endl;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other) {

	(void)other;
	std::cout << "IMateriaSource (assignment operator=)" << std::endl;
	return *this;
}

