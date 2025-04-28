#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {
	
	// const Animal* meta = new Animal();
	// const Animal*	j = new Dog();
	// const Animal*	i = new Cat();

	// std::cout << j->getType() << " " << std::endl;
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;

	// i->makeSound();
	// j->makeSound();
	// delete j;
	// delete meta;
	// delete i;


	// std::cout << std::endl;

	// Animal	ana = Animal();
	// ana.makeSound();
	// ana = Cat();
	// std::cout << ana.getType() << ": ";
	// ana.makeSound();

	std::cout << std::endl;

	const WrongAnimal*	wani = new WrongAnimal();
	const WrongAnimal*	wcat = new WrongCat();

	std::cout << wani->getType() << " " << std::endl;
	wani->makeSound();
	std::cout << wcat->getType() << " " << std::endl;
	wcat->makeSound();

	delete wani;
	delete wcat;

	std::cout << std::endl;



	return (0);
}