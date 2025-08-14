#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <ostream>

// Constructor
AForm::AForm(std::string name, const int gradeToSign, const int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (_gradeToSign < 0 || _gradeToExecute < 0) {
		throw AForm::GradeTooLowException("Grade too low.");
	} else if (_gradeToSign > 150 || _gradeToExecute > 150) {
		throw AForm::GradeTooHighException("Grade too high.");
	}
}

AForm::AForm() : _name("Default"), _isSigned(), _gradeToSign(), _gradeToExecute() {
}

// Copy Constructor
AForm::AForm(const AForm &object)
    : _name(object.getName()), _isSigned(object.getIsSigned()), _gradeToSign(object.getGradeToSign()),
      _gradeToExecute(object.getGradeToExecute()) {
}

// Operator =
AForm &AForm::operator=(const AForm &object) {
	if (this != &object) {
		this->_isSigned = object.getIsSigned();
		// _name, _gradeToSign, and _gradeToExecute are likely const or should
		// not be assigned
	}
	return *this;
}

// Operator <<
std::ostream &operator<<(std::ostream &os, const AForm &object) {
	os << "AForm: " << object.getName() << ", Signed: ";
	if (object.getIsSigned()) {
		std::cout << "'True'";
	} else {
		std::cout << "'False'";
	}
	std::cout << ", Grade to Sign: " << object.getGradeToSign() << ", Grade to Execute: " << object.getGradeToExecute();
	return os;
}

// Destructor
AForm::~AForm() {
}

// Getters
const std::string &AForm::getName() const {
	return this->_name;
}

const bool &AForm::getIsSigned() const {
	return this->_isSigned;
}

const int &AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

const int &AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

// Members functions
void AForm::beSigned(const Bureaucrat &object) {
	if (object.getGrade() <= this->_gradeToSign) { // Grade is High Enough
		this->_isSigned = true;
	} else {
		throw AForm::GradeTooLowException();
	}
}

// You must check that the form is signed and that the grade of the bureaucrat at-
// tempting to execute the form is high enough. Otherwise, throw an appropriate exception.
void AForm::execute(Bureaucrat const &executor) const {

	if (!_isSigned) {
		throw AForm::IsSignedException();
	} else if (executor.getGrade() > _gradeToExecute) {
		throw AForm::GradeTooLowException();
	}

	this->executeAction();
}

// Ghost function to be implemented in derived classes
void AForm::executeAction() const {};

// Ghost function to be implemented in derived classes
const std::string AForm::getTarget() const {
	return "Default Target";
}

// Ghost function to be implemented in derived classes
int AForm::getSignGrade() const {
    return this->_gradeToSign;
}

// Ghost function to be implemented in derived classes
int AForm::getExecuteGrade() const {
    return this->_gradeToExecute;
}