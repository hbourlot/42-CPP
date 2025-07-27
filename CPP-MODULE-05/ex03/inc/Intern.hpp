#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

class Intern {

  private:
	// Copy Constructor
	Intern(const Intern &object);

	// Operator =
	Intern &operator=(const Intern &object);

  public:
	// Default Constructor
	Intern();

	// Destructor
	~Intern();

	AForm *makeForm(std::string formName, std::string formTarget);
};