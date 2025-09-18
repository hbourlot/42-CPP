#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm {

  private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;

  public:
	// Default Constructor
	AForm();

	// Constructor
	AForm(std::string name, const int gradeToSign, const int gradeToExecute);

	// Copy Constructor
	AForm(const AForm &object);

	// Operator =
	AForm &operator=(const AForm &object);

	// Operator <<
	friend std::ostream &operator<<(std::ostream &os, const AForm &object);

	// Destructor
	virtual ~AForm();

	// Getters
	const std::string &getName() const;
	const bool &getIsSigned() const;
	const int &getGradeToSign() const;
	const int &getGradeToExecute() const;

	// Members functions
	void beSigned(const Bureaucrat &object); // Change to signed if grade is
	                                         //   enough (greater than or
	                                         // equal to the required one)

	// Class exception
	class GradeTooLowException : public std::exception {
	  private:
		std::string _message;
	public:
		explicit GradeTooLowException(const std::string &message = "Grade too Low.") : _message(message) {
		}
		const char *what() const throw() {
			return _message.c_str();
		};
		~GradeTooLowException() throw() {};
	};

	class GradeTooHighException : public std::exception {
		private:
			std::string _message;
	  	public:
			explicit GradeTooHighException(const std::string &message = "Grade too High.") : _message(message) {};
			~GradeTooHighException() throw() {};
		
	};

	class IsSignedException : public std::exception {
		private:
			std::string _message;
		public:
			explicit IsSignedException(const std::string &message = "Form isn't signed.") : _message(message) {};
			~IsSignedException() throw() {};
	};

	void execute(Bureaucrat const &executor) const;

	// Virtual member function to be implemented in derived classes
	virtual void executeAction() const;
	virtual const std::string getTarget() const;
	virtual int getSignGrade() const;
	virtual int getExecuteGrade() const;
};