#pragma once

#include "AForm.hpp"
#include <iostream>

// Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.
class PresidentialPardonForm : public AForm {

  private:
	std::string _target;

  public:
	// Constructor
	PresidentialPardonForm(std::string target);

	// Default Constructor
	PresidentialPardonForm();

	// Copy Constructor
	PresidentialPardonForm(const PresidentialPardonForm &object);

	// Operator =
	PresidentialPardonForm &operator=(const PresidentialPardonForm &object);

	// Destructor
	~PresidentialPardonForm();

	// Virtual Member
	void executeAction() const;
};