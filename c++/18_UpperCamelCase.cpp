#include <iostream>

class Zombie {
	private:
		std::string 	name;
		std::string		last_name;

	public:
		Zombie(std::string n, std::string l) : name(n), last_name(l) {}

		void announce() {
			std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
			std::cout << last_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
		}

		~Zombie() {
			std::cout << name << " is destroyed!" << std::endl;
		};
};

Zombie*	newZombie ( std::string name );
void	randomChump ( std::string name );


Zombie* newZombie (std::string name) {
	return new Zombie(name, "laele");
}

void	randomChump ( std::string name ) {
	Zombie hugo = Zombie(name, "laele");
	Zombie zom(name, "laele");
	zom.announce();
}

int		main() {

	Zombie* name = newZombie("Ze");
	name->announce();
	name->~Zombie();

	randomChump("Matador de aluguel");
}