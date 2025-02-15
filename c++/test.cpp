#include <iostream>



int	main() {
	
	std::string name = "Hugo";
	std::string name1 = "Hugo Arthur aaaaaaaaaaa";
	char name1[] = "Hugo";

	std::cout << "size: " << sizeof(name) << std::endl;
	std::cout << "size: " << sizeof(name1) << std::endl;
	std::cout << "capacity: " << name.capacity() << std::endl;
	std::cout << "capacity: " << name1.capacity() << std::endl;


	std::cout << "SSize: " << sizeof(std::string) << std::endl;
	std::cout << "size: " << sizeof(name1) << std::endl;

	return 0;

}