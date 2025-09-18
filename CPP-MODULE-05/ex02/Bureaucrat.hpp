#pragma once

class AForm;

#include "AForm.hpp"
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
	void signForm(AForm &object); // success will print -><bureaucrat> signed
	                              // <form> and fail
	                              // -> <bureaucrat> couldn’t sign <form>
	                              // because <reason>

	// Class Error exception
	class GradeTooHighException : public std::runtime_error {
	  public:
		explicit GradeTooHighException(const std::string &message = "Grade too High.") : std::runtime_error(message) {
		}
	};

	class GradeTooLowException : public std::runtime_error {
	  public:
		explicit GradeTooLowException(const std::string &message = "Grade too Low.") : std::runtime_error(message) {
		}
	};

	class BureaucratException : public std::runtime_error {
	  public:
		explicit BureaucratException(const std::string &message) : std::runtime_error(message){};
	};

	// Getters
	const std::string &getName() const;
	const int &getGrade() const;

	void executeForm(AForm const &form) const;
};

// class MyError2 {
// 	private:
// 		std::string _message;

// 	public:
// 		MyError2(const std::string &message) : _message(message) {
// 		}
// 		const std::string &what() const {
// 			return _message;
// 		}
// };

// class MyError3 : public std::exception {
// 	private:
// 		std::string _message;

// 	public:
// 		MyError3(const std::string &message) : _message(message) {
// 		}
// 		virtual const char *what() const throw() {
// 			return _message.c_str();
// 		}
// };