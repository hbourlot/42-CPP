#include "Bureaucrat.hpp"
#include <ostream>
#include <stdexcept>

// Constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {

	if (grade < 1) {
		throw Bureaucrat::GradeTooLowException("Grade too low.");
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooHighException("Grade too high.");
	}
}

// Default Constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(0) {
		if (_grade < 1) {
		throw Bureaucrat::GradeTooLowException("Grade too low.");
	} else if (_grade > 150) {
		throw Bureaucrat::GradeTooHighException("Grade too high.");
	}
};

// Destructor
Bureaucrat::~Bureaucrat() {
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &object) :  _name(object.getName()), _grade(object.getGrade()) {
}

// Overload =
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &object) {

	if (this != &object) {
		this->_grade = object.getGrade();
	}

	return *this;
}

// Overload <<
std::ostream &operator<<(std::ostream &os, const Bureaucrat &object) {

	os << object.getName() << ", bureaucrat grade " << object.getGrade();

	return os;
}

// Members
void Bureaucrat::increaseGrade() {
	this->_grade = _grade - 1;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decreaseGrade() {
	this->_grade = _grade + 1;
	if (this->_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

// Getters
const std::string &Bureaucrat::getName() const {
	return this->_name;
}

const int &Bureaucrat::getGrade() const {
	return this->_grade;
}
