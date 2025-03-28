#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	
	delete meta;
	delete j;
	delete i;
	
	const WrongAnimal* wrong = new WrongCat();
	wrong->makeSound();
	delete wrong;

	Animal any2("Anonymous");
	Animal any(any2);

	any = any2;
	any.makeSound();
	
	return 0;
}