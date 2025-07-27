#pragma once

#include "AForm.hpp"
#include <iostream>
#include <stdexcept>

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
	class ShrubberyCreationFormException : public std::runtime_error {
	  public:
		explicit ShrubberyCreationFormException(const std::string &message = "Shrubbery Exception")
		    : std::runtime_error(message) {};
	};

	// Constructor
	ShrubberyCreationForm(std::string target);

	// Copy Constructor
	ShrubberyCreationForm(const ShrubberyCreationForm &object);

	// Operator =
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &object);

	// Destructor
	~ShrubberyCreationForm();

	// Virtual Member
	void executeAction() const;
};