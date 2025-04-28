#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

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

	// std::cout << std::endl;

	// const WrongAnimal*	wani = new WrongAnimal();
	// const WrongAnimal*	wcat = new WrongCat();

	// std::cout << wani->getType() << " " << std::endl;
	// wani->makeSound();
	// std::cout << wcat->getType() << " " << std::endl;
	// wcat->makeSound();

	// delete wani;
	// delete wcat;

	// std::cout << std::endl;


	const Animal *an[10];
	// Animal ani;

	for (int i = 0; i < 10; i++) {

		if (i < 5) {
			an[i] = new Cat();
		} else {
			an[i] = new Dog();
		}
		if (an[i] == NULL) {
			std::cerr << "Fail allocation" << std::endl;

			for (int j = i; j >= 0; j--) {
				delete an[j];
				return (1);
			}
			break;
		}
	}

	for (int i = 0; i < 10; i++) {
		an[i]->makeSound();
	}
	for (int i = 0; i < 10; i++) {
		delete an[i];
	}

	Cat*		d = new Cat();
	Cat			c;

	
	// c = *d;
	for (int i = 0; i < 100; i++) {
		d->setIdea(i, "LAELE");
	}
	
	c = *d;
	delete d;
	for (int i = 0; i < 100; i++) {
		std::cout << c.getIdea(i) << std::endl;
	}
	return (0);
}