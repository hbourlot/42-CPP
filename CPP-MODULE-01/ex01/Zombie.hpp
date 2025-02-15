#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

	private:
		std::string _name;

	public:
		
		Zombie() {};
		~Zombie () {
			// std::cout  << "adios zombie\n";
		}
		void announce( void );
		
		// SETTER
		void setName(std::string name);


};

void	randomChump( std::string name );
Zombie*	zombieHorde(int N, std::string name );
void announceHorde(int N, Zombie *horde);

#endif