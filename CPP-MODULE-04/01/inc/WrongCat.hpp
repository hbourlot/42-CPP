#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	private:
		//

	public:

		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat& other);
		~WrongCat();
		WrongCat& operator=(const WrongCat& other);

		void	makeSound( void ) const;
		// std::string getType( void ) const;
};