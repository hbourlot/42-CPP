#pragma once

#include "AForm.hpp"
#include <iostream>

struct AForm;

// Required grades: sign 145, exec 137
// Creates a file <target>_shrubbery in the working directory and writes ASCII trees
// inside it.
class ShrubberyCreationForm : public AForm {

	private:
		std::string _target;

		// Default Constructor
		ShrubberyCreationForm();

	public:
		// Constructor
		ShrubberyCreationForm(std::string target);

		// Copy Constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &object);

		// Operator =
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &object);

		// Destructor
		~ShrubberyCreationForm();
};