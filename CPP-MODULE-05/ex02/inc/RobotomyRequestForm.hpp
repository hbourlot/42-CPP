#pragma once

#include "AForm.hpp"
#include <iostream>

// Required grades: sign 72, exec 45
// Makes some drilling noises, then informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, it informs that the robotomy failed.
class RobotomyRequestForm : public AForm {

  private:
	std::string _target;

  public:
	// Constructor
	RobotomyRequestForm(std::string target);

	// Default Constructor
	RobotomyRequestForm();

	// Copy Constructor
	RobotomyRequestForm(const RobotomyRequestForm &object);

	// Operator =
	RobotomyRequestForm &operator=(const RobotomyRequestForm &object);

	// Destructor
	~RobotomyRequestForm();

	// Virtual Member
	void executeAction() const;
};