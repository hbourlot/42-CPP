#include <iostream>

namespace first {
	int x = 10;
}

namespace second {
	int x = 20;
}

int main() {

	// using namespace first;

	// std::cout << x;

	///////////////////////////////////////////////////
	// int x = 0;

	// std::cout << second::x;
	///////////////////////////////////////////////////


	// using namespace std;
	// string name = "Hugo";
	// cout << "Hello " << name;

	using std::cout;
	using std::string;

	string name = "Hugo";
	cout << "Hello " << name;


	//* Namespace = provides a solution for preventing name conflicts
	//*				in large projects. Each entity needs a unique name.
	//*				A namespace allows for identically named entities
	//*				as long as the namespaces are different.
	return 0;
}
