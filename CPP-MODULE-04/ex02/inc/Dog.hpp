#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {

	private:
		Brain *_brain;
	
	public:
	
		Dog( void );
		Dog(Dog& other);
		~Dog( void );
		Dog&	operator=(const Dog& other);
		void	makeSound( void ) const; // Polymorphism
		void	setIdeas(size_t i, std::string idea) const;
		void	getIdeas( void ) const;
		void	getInfo( void ) const;

		
};

#endif