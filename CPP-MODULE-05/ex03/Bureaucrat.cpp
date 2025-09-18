#include "Bureaucrat.hpp"
#include <ostream>

// Constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooLowException("Grade too low.");
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooHighException("Grade too high.");
	}
}

// Default Constructor
Bureaucrat::Bureaucrat() : _name(), _grade() {}

// Destructor
Bureaucrat::~Bureaucrat(){};

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &object) : _name(object.getName()), _grade(object.getGrade()) {
}
// Overload =
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &object) {

	if (this != &object) {
		this->_grade = object.getGrade();
	}

	return *this;
};

// Overload <<
std::ostream &operator<<(std::ostream &os, const Bureaucrat &object) {

	os << object.getName() << ", bureaucrat grade " << object.getGrade() << std::endl;

	return os;
};

// Members
void Bureaucrat::increaseGrade() {
	this->_grade = _grade - 1;
	if (this->_grade < 0)
		throw Bureaucrat::GradeTooHighException("Grade too Low.");
};

void Bureaucrat::decreaseGrade() {
	this->_grade = _grade + 1;
	if (this->_grade > 150) {
		throw Bureaucrat::GradeTooLowException("Grade too high.");
	}
};

void Bureaucrat::signForm(AForm &object) {

	AForm *totem = &object;

	if (!totem) {
		throw BureaucratException("Error Null Memory.");
		return;
	}

	try {
		object.beSigned(*this);
		std::cout << this->getName() << " signed " << object.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << this->getName() << " couldn't sign " << object.getName() << " because " << e.what() << std::endl;
	}
};

// Getters
const std::string &Bureaucrat::getName() const {
	return this->_name;
};

const int &Bureaucrat::getGrade() const {
	return this->_grade;
};

void Bureaucrat::executeForm(AForm const &form) const {

	try {
		form.executeAction();
		std::cout << _name << " executed " << form.getName();
	} catch (std::exception &e) {
		std::cout << "ExecuteForm Error: " << e.what() << std::endl;
	}
};