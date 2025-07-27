#include "../inc/PresidentialPardonForm.hpp"
#include <filesystem>

// Constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardon", 25, 5), _target(target) {};

// Ddefault Constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm(), _target() {};

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &object) {
	_target = object._target;
	// AForm
}

// Operator =
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &object) {

	if (this != &object) {
		_target = object._target;
		// AForm
	}

	return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {};

// Virtual Member
void PresidentialPardonForm::executeAction() const {

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox.";
}
