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
		~AForm();

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
		class GradeTooLowException : public std::runtime_error {
			public:
				explicit GradeTooLowException(const std::string &message = "Grade too Low.")
					: std::runtime_error(message) {
				}
		};

		class GradeTooHighException : public std::runtime_error {
			public:
				explicit GradeTooHighException(const std::string &message = "Grade too High.")
					: std::runtime_error(message) {};
		};

		class IsSignedException : public std::runtime_error {
			public:
				explicit IsSignedException(const std::string &message = "Form already Signed.")
					: std::runtime_error(message) {};
		};

		void execute(Bureaucrat const &executor) const;
};