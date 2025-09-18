#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

	// std::cout << "\033[31m";
	// std::cout << "\n******************************************";
	// std::cout << "\n*********TESTING FORM CRATION*************";
	// std::cout << "\n******************************************\n" << std::endl;
	// std::cout << "\033[0m";

	Intern someRandomIntern;
	AForm *rrf;
	AForm *pp;
	AForm *shrubbery;

	rrf = someRandomIntern.makeForm("RobotomyRequest", "Bender");
	pp = someRandomIntern.makeForm("PresidentialPardon", "Prison");
	shrubbery = someRandomIntern.makeForm("ShrubberyCreation", "Garden");

	std::cout << "\033[31m";
	std::cout << "\n******************************************";
	std::cout << "\n*********TESTING WRONG FORMS 1 **************";
	std::cout << "\n******************************************\n" << std::endl;
	std::cout << "\033[0m";

	AForm *error;
	AForm *error2;

	error = someRandomIntern.makeForm("Empty", "Bender");
	error2 = someRandomIntern.makeForm("presidential pardonn", "Bender");

	std::cout << "\033[31m";
	std::cout << "\n******************************************";
	std::cout << "\n*********TESTING SIGNING FORMS 2 ************";
	std::cout << "\n******************************************\n" << std::endl;
	std::cout << "\033[0m";

	Bureaucrat *hugo = new Bureaucrat("hugo", 100);

	try {
		hugo->signForm(*rrf);
		hugo->signForm(*pp);
		hugo->signForm(*shrubbery);
		shrubbery->execute(*hugo);
		hugo->signForm(*error);
		hugo->signForm(*error);
	} catch (std::exception &msg) {
		std::cout << "ERROR: " << msg.what() << std::endl;
	}

	delete rrf;
	delete pp;
	delete shrubbery;
	delete error;
	delete error2;
	delete hugo;
};