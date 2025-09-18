#include "RobotomyRequestForm.hpp"
#include <sys/types.h>

// Constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45), _target(target){};

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm(), _target("NULL"){};

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &object) : AForm(object), _target(object._target){};

// Operator =
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &object) {

	if (this != &object) {
		_target = object._target;
		// AForm
	}
	return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm(){};

// Virtual Member
void RobotomyRequestForm::executeAction() const {

	int odd;

	odd = rand() % 2;

	std::cout << "Making drilling noises 🔉\n";

	odd == 1 ? std::cout << _target << " has been robotomized successfully!" << std::endl
	         : std::cout << "robotomy failed!\n";
};

// Getters
const std::string RobotomyRequestForm::getTarget() const {
	return _target;
};
