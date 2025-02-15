#include "Zombie.cpp"

int main(void) {

	Zombie* allocated_zombie = newZombie("Hello moto");
	allocated_zombie->announce();
	delete allocated_zombie;

	randomChump("Zezin");

	return 0;
}