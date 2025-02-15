#include <iostream>

using namespace std;

class Animal {
	private:
		string 	name;
		int 	age;

	public:
		Animal(string n, int a) {
			name = n;
			age = a;
		}

		void display() {
			std::cout << "Name : " << name << "Age: " << age << std::endl;
		}
};


int	main(int argc, char *argv[]) {

	Animal cat("Whiskers", 3);

	cat.display();

}