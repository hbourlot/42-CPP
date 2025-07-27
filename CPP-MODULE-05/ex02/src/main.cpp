#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>

int main() {

	std::cout << "\n*********CREATING FORMS AND BUREAUCRAT**********\n" << std::endl;

	AForm *shrubbery = new ShrubberyCreationForm("house");
	AForm *robot = new RobotomyRequestForm("human");
	AForm *pardon = new PresidentialPardonForm("human");
	Bureaucrat *president = new Bureaucrat("President", 1);
	Bureaucrat *hugo = new Bureaucrat("Hugo", 100);
	Bureaucrat *powerless = new Bureaucrat("Powerless", 150);

	std::cout << "\033[31m";
	std::cout << "\n***************************************";
	std::cout << "\n*********TESTING SHRUBERRY*************";
	std::cout << "\n***************************************\n";
	std::cout << "\033[0m";

	std::cout << "\n*********TRY EXECUTE SHRUBERRY WITHOUT SIGNING**********\n" << std::endl;
	try {
		// ShrubberyCreationForm form("house");
		// AForm& shrubbery = form; //Prevent object slicing
		std::cout << "Form name: " << shrubbery->getName() << " | Target: " << shrubbery->getTarget()
		          << " | Sign grade: " << shrubbery->getGradeToSign()
		          << " | Execute grade: " << shrubbery->getGradeToExecute() << std::endl;
		shrubbery->execute(*hugo);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}

	std::cout << "\033[32m";
	std::cout << "\n*********TRY EXECUTE SHRUBERRY**********\n" << std::endl;
	std::cout << "\033[0m";
	try {
		president->signForm(*shrubbery);
		shrubbery->execute(*president);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}

	std::cout << "\033[32m";
	std::cout << "\n*********TRY EXECUTE SHRUBERRY WITHOUT ENOUGH GRADE**********\n" << std::endl;
	std::cout << "\033[0m";

	try {
		powerless->signForm(*shrubbery);
		shrubbery->execute(*powerless);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}

	std::cout << "\033[31m";
	std::cout << "\n***************************************";
	std::cout << "\n*********TESTING ROBOTREQUEST**********";
	std::cout << "\n***************************************\n";
	std::cout << "\033[0m";

	std::cout << "\033[32m";
	std::cout << "\n*********TRY EXECUTE ROBOT WITHOUT SIGNING**********\n" << std::endl;
	std::cout << "\033[0m";

	try {

		std::cout << "Form name: " << robot->getName() << " | Target: " << robot->getTarget()
		          << " | Sign grade: " << robot->getSignGrade() << " | Execute grade: " << robot->getExecuteGrade()
		          << std::endl;
		robot->execute(*hugo);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}

	std::cout << "\033[32m";
	std::cout << "\n*********TRY EXECUTE ROBOT**********\n" << std::endl;
	std::cout << "\033[0m";

	try {
		president->signForm(*robot);
		robot->execute(*president);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}

	std::cout << "\033[32m";
	std::cout << "\n*********TRY EXECUTE ROBOT WITHOUT ENOUGH GRADE**********\n" << std::endl;
	std::cout << "\033[0m";

	try {
		powerless->signForm(*robot);
		robot->execute(*powerless);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}

	std::cout << "\033[31m";
	std::cout << "\n**********************************************";
	std::cout << "\n*********TESTING PRESIDENTIAL PARDON**********";
	std::cout << "\n**********************************************\n";
	std::cout << "\033[0m";

	std::cout << "\033[32m";
	std::cout << "\n*********TRY EXECUTE PRESIDENTIAL PARDON WITHOUT SIGNING**********\n" << std::endl;
	std::cout << "\033[0m";

	try {

		std::cout << "Form name: " << pardon->getName() << " | Target: " << pardon->getTarget()
		          << " | Sign grade: " << pardon->getSignGrade() << " | Execute grade: " << pardon->getExecuteGrade()
		          << std::endl;
		pardon->execute(*hugo);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}

	std::cout << "\033[32m";
	std::cout << "\n*********TRY EXECUTE PRESIDENTIAL PARDON**********\n" << std::endl;
	std::cout << "\033[0m";

	try {
		president->signForm(*pardon);
		pardon->execute(*president);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}

	std::cout << "\033[32m";
	std::cout << "\n*********TRY EXECUTE PRESIDENTIAL PARDON WITHOUT ENOUGH GRADE**********\n" << std::endl;
	std::cout << "\033[0m";

	try {
		powerless->signForm(*pardon);
		pardon->execute(*powerless);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}


	delete shrubbery;
	delete robot;
	delete pardon;
	delete hugo;
	delete president;
	delete powerless;
	return 0;

};