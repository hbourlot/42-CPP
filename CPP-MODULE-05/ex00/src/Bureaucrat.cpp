#include "Bureaucrat.hpp"
#include <ostream>

// Constructor
Bureaucrat::Bureaucrat(int grade, std::string name)
	: _grade(grade), _name(name) {

	if (grade < 0) {
		throw Bureaucrat::GradeTooLowException("Grade too low.");
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooHighException("Grade too high.");
	}
}

// Destructor
Bureaucrat::~Bureaucrat() {
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &object)
	: _grade(object.getGrade()), _name(object.getName()) {
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

	os << object.getName() << ", bureaucrat grade " << object.getGrade()
	   << std::endl;

	return os;
}

// Members
void Bureaucrat::increaseGrade() {
	this->_grade = getGrade() - 1;
	if (this->_grade < 0)
		throw Bureaucrat::GradeTooLowException("Grade too Low.");
}

void Bureaucrat::decreaseGrade() {
	this->_grade = getGrade() + 1;
	if (this->_grade > 150) {
		throw Bureaucrat::GradeTooHighException("Grade too high.");
	}
}

// Getters
const std::string &Bureaucrat::getName() const {
	return this->_name;
}

const int &Bureaucrat::getGrade() const {
	return this->_grade;
}
