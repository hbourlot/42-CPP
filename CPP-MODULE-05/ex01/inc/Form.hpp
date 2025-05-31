#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <string>

class Form {

	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		// Constructor
		Form();

		// Copy Constructor
		Form(const Form &object);

		// Operator =
		Form &operator=(const Form &object);

		// Operator <<
		friend std::ostream &operator<<(std::ostream &os, const Form &object);

		// Destructor
		~Form();

		// Getters
		const std::string &getName() const;
		const bool &getIsSigned() const;
		const int &getGradeToSign() const;
		const int &gradeToExecute() const;

		// Members functions
		void beSigned(const Bureaucrat &object); // Change to signed if grade is
												 // high enough (greater than or
												 // equal to the required one)
		void
		signForm(); // success will print -><bureaucrat> signed <form> and fail
					// -> <bureaucrat> couldn’t sign <form> because <reason>
}