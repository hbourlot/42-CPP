#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
	
	private:
		Brain* _brain;

	public:
	
		Cat( void );
		Cat(const Cat& other);
		~Cat( void );
		void	makeSound( void ) const; // Polymorphism
		Cat&	operator=(const Cat& other);
		void	setIdeas(size_t i, std::string idea) const;
		void	getIdeas( void ) const;
		void	getInfo( void ) const;
};
