#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int main() {

	// Bureaucrat me(51, "Hugo");
	// try {

	// 	std::cout << me;

	// 	me.decreaseGrade();
	// 	// me.decreaseGrade();
	// 	std::cout << me;

	// } catch (std::exception &e) {
	// 	std::cout << "Caught error: " << e.what() << std::endl;
	// }

	// try {
	// 	Form hugo("Hugo", 50, 100);
	// 	std::cout << hugo << std::endl;
	// 	me.signForm(hugo);
	// 	// std::cout << hugo << std::endl;

	// } catch (std::exception &e) {
	// 	std::cout << "Caught error: " << e.what() << std::endl;
	// }

	std::cout << "\n*********TESTING CONSTRUCTOR**********\n" << std::endl;
	try {
		Form test("test1", 10, 190);
	} catch (std::exception &msg) {
		std::cout << "test1 -> Error: " << msg.what() << std::endl;
	}

	try {
		Form test1("test1", 10, 0);
	} catch (std::exception &msg) {
		std::cout << "test1 -> Error: " << msg.what() << std::endl;
	}

	try {
		Form test2("test2", 190, 10);
	} catch (std::exception &msg) {
		std::cout << "test2 -> Error: " << msg.what() << std::endl;
	}

	try {
		Form test3("test3", 0, 100);
	} catch (std::exception &msg) {
		std::cout << "test3 -> Error: " << msg.what() << std::endl;
	}

	std::cout << "\n*********TESTING GRADE 10 FORM 100**********\n" << std::endl;
	try {
		Bureaucrat hugo("hugo", 10);
		Form form("test", 100, 120);
		hugo.signForm(form);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}

	std::cout << "\n*********TESTING GRADE 10 FORM 1**********\n" << std::endl;
	try {
		Bureaucrat hugo("hugo", 10);
		Form form("test", 1, 120);
		hugo.signForm(form);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}

	std::cout << "\n*********TESTING GRADE 10 FORM 10**********\n" << std::endl;
	try {
		Bureaucrat hugo("hugo", 10);
		Form form("test", 10, 120);
		hugo.decreaseGrade();
		hugo.signForm(form);
		hugo.increaseGrade();
		hugo.increaseGrade();
		hugo.signForm(form);
		hugo.signForm(form);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}

	return 0;
}