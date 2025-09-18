#include "Intern.hpp"
#include <cstddef>
#include <iostream>
#include <string>

// Constructor
Intern::Intern(){};

// Copy Constructor
Intern::Intern(const Intern &object) {
	(void)object;
}

// Operator =
Intern &Intern::operator=(const Intern &object) {
    (void)object;
    return *this;
}

// Destructor
Intern::~Intern(){};

AForm *Intern::makeForm(std::string formName, std::string formTarget) {
	std::string formOptions[3] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
	AForm *totem = NULL;

	int i = 0;
	for (; i < 3; ++i) {
		if (formOptions[i] == formName)
			break;
	}

	switch (i) {
		case 0:
			totem = new PresidentialPardonForm(formTarget);
			break;
		case 1:
			totem = new RobotomyRequestForm(formTarget);
			break;
		case 2:
			totem = new ShrubberyCreationForm(formTarget);
			break;
		default:
			std::cerr << "Invalid form: " << formName << std::endl;
			return NULL;
	}

	std::cout << "Intern creates " << formOptions[i] << " Form" << std::endl;
	return totem;
};