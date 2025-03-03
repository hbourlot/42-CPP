#include "Animal.hpp"
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"



int main()
{


	const	Animal*	j = new Dog();
	const	Animal*	i = new Cat();

	delete j;
	delete i;

	std::cout << "--- Animal (Cat) Objects ---\n\n";
	const Cat* c = new Cat();
	c->setIdeas(50, "💡 Miau??");
	c->getIdeas();
	c->setIdeas(101, "💡 Miau??");
	delete c;
	
	const Cat c1;
	c1.setIdeas(3, "💡 Miau??");
	c1.getIdeas();
	// const Dog* d = new Cat();
	std::cout << "__ End Objects \n\n";
	std::cout << "\n\n";


	std::cout << "--- Animal (Dog) Objects ---\n\n";
	const Dog* d = new Dog();
	d->setIdeas(50, "💡 ruff??");
	d->getIdeas();
	d->setIdeas(101, "💡 ruff??");
	delete d;

	const Dog d1;
	d1.setIdeas(3, "💡 ruff??");
	d1.getIdeas();

	std::cout << "__ End Objects \n\n";
	std::cout << "\n\n";


	std::cout << "--- Deep copy test (Dog) ---\n\n";
	Dog d2;
	std::cout << "\n-> Before set idea\n";
	d2.getInfo();
	d2.setIdeas(1, "Ruff");
	Dog d3 = d2;
	std::cout << "\n-> After set idea\n";
	d2.getInfo();
	d3.getInfo();
	std::cout << "\n";

	std::cout << "--- Deep copy test (Cat) ---\n\n";
	Cat c2;
	std::cout << "\n-> Before set idea\n";
	c2.getInfo();
	c2.setIdeas(1, "Ruff");
	Cat c3 = c2;
	std::cout << "\n-> After set idea\n";
	c2.getInfo();
	c3.getInfo();
	std::cout << "\n";
	
	return 0;
}