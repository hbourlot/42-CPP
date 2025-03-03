#pragma once

#include <iostream>
#include <string>

class Brain {
	
	private:
		std::string	ideas[100];
	
	public:
		Brain( void );
		Brain ( const Brain& other );
		~Brain( void );
		Brain&		operator=(const Brain& other);
		void		setIdea( size_t i, std::string idea);
		std::string getIdea( size_t i ) const;
};