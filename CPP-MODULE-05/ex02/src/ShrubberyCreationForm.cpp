#include "../inc/ShrubberyCreationForm.hpp"

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target() {};

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target + "_shruberry") {};

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &object) {
	_target = object._target;
	// AForm::
};

// Operator =
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &object) {

	_target = object._target;
	// AForm::

	return *this;
};

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {};