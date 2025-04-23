#pragma once

#include <iostream>

class Brain {

	private:

		std::string _ideas[100];

		void	fillIdeas(std::string idea) ;
	public:

			Brain();
			Brain(std::string idea);
			Brain(const Brain& other);
			~Brain();

			Brain& operator=(const Brain& other);
			const std::string* getIdeas( void ) const;
			void		setIdea(int idx, std::string idea);
			void		setIdeas(const std::string* ideas);

};
