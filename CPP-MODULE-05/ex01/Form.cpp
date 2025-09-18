#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

// Constructor
Form::Form(std::string name, const int gradeToSign, const int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {

	if (_gradeToSign < 1 || _gradeToExecute < 1) {
		throw Form::GradeTooLowException("Grade too low.");
	} else if (_gradeToSign > 150 || _gradeToExecute > 150) {
		throw Form::GradeTooHighException("Grade too high.");
	}
}

Form::Form() : _name("Default"), _isSigned(), _gradeToSign(), _gradeToExecute() {
}

// Copy Constructor
Form::Form(const Form &object)
    : _name(object.getName()), _isSigned(object.getIsSigned()), _gradeToSign(object.getGradeToSign()),
      _gradeToExecute(object.getGradeToExecute()) {
}

// Operator =
Form &Form::operator=(const Form &object) {
	if (this != &object) {
		this->_isSigned = object.getIsSigned();
		// _name, _gradeToSign, and _gradeToExecute are likely const or should
		// not be assigned
	}
	return *this;
}

// Operator <<
std::ostream &operator<<(std::ostream &os, const Form &object) {
	os << "Form: " << object.getName() << ", Signed: ";
	if (object.getIsSigned()) {
		std::cout << "'True'";
	} else {
		std::cout << "'False'";
	}
	std::cout << ", Grade to Sign: " << object.getGradeToSign() << ", Grade to Execute: " << object.getGradeToExecute();
	return os;
}

// Destructor
Form::~Form() {
}

// Getters
const std::string &Form::getName() const {
	return this->_name;
}

const bool &Form::getIsSigned() const {
	return this->_isSigned;
}

const int &Form::getGradeToSign() const {
	return this->_gradeToSign;
}

const int &Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

// Members functions
void Form::beSigned(const Bureaucrat &object) {
	if (object.getGrade() <= this->_gradeToSign) { // Grade is High Enough
		this->_isSigned = true;
	} else {
		throw Form::GradeTooLowException();
	}
}
