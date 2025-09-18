#pragma once

class Form;

#include "Form.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

class Bureaucrat {

  private:
	const std::string _name;
	int _grade; // Range 1 [max] to 150 [min]

  public:
	// Constructor
	Bureaucrat(std::string name, int grade);
	Bureaucrat();

	// Destructor
	~Bureaucrat();

	// Copy constructor
	Bureaucrat(const Bureaucrat &object);

	// Operator =
	Bureaucrat &operator=(const Bureaucrat &object);

	// Operator <<
	friend std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

	// Members

	void increaseGrade();
	void decreaseGrade();
	void signForm(Form &object); // success will print -><bureaucrat> signed
	                             // <form> and fail
	                             // -> <bureaucrat> couldn’t sign <form>
	                             // because <reason>

	// Class Error exception
	class GradeTooHighException : public std::exception {
		private:
			std::string _message;
		public:
		explicit GradeTooHighException(const std::string &message = "Grade too High.") : _message(message) {
		}
		const char *what() const throw() {
			return _message.c_str();
		}
		~GradeTooHighException() throw(){};
	};

	class GradeTooLowException : public std::exception {
		private:
			std::string _message;
		public:
		explicit GradeTooLowException(const std::string &message = "Grade too Low.") : _message(message) {
		}
		const char *what() const throw() {
			return _message.c_str();
		}
		~GradeTooLowException() throw(){};
	};

	class BureaucratException : public std::exception {
		private:
			std::string _message;
		public:
		explicit BureaucratException(const std::string &message) : _message(message){};
		
		const char *what() const throw() {
			return _message.c_str();
		}
		~BureaucratException() throw(){};
	};

	// Getters
	const std::string &getName() const;
	const int &getGrade() const;
};
