#pragma once

#include "AForm.hpp"
#include <iostream>
#include <stdexcept>


// Required grades: sign 145, exec 137
// Creates a file <target>_shrubbery in the working directory and writes ASCII trees
// inside it.
class ShrubberyCreationForm : public AForm {

  private:
	std::string _target;

	// Default Constructor
	ShrubberyCreationForm();

  public:
	class ShrubberyCreationFormException : public std::exception {
	  
		private:
			std::string _message;
		public:
		explicit ShrubberyCreationFormException(const std::string &message = "Shrubbery Exception")
		    : _message(message) {};
		const char *what() const throw() {
			return _message.c_str();
		}
		~ShrubberyCreationFormException() throw(){};
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

	// Getters
	const std::string getTarget() const;
};