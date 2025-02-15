#include "Zombie.hpp"


void announceHorde(int N, Zombie *horde) {
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
}


int main (void) {

	Zombie *horde = zombieHorde(10, "Zezin");

	announceHorde(10, horde);
	delete[] horde;
	return 0;
}