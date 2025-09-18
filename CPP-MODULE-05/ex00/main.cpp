#include "./Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

// Custom exception classes for demonstration
class MyError : public std::runtime_error {
  public:
	MyError(const std::string &msg) : std::runtime_error(msg) {
	}
};

class DataBaseError : public MyError {
  private:
	int _errorCode;

  public:
	DataBaseError(const std::string &message, int errorCode) : MyError(message), _errorCode(errorCode) {
	}
	int getErrorCode() const {
		return _errorCode;
	}
};

// Function that throws MyError to test exception propagation
void throwError(const MyError &e) {
	throw e;
}

void testBureaucratGrades() {
	try {
		std::cout << "Creating Bureaucrat with grade 1 (highest)" << std::endl;
		Bureaucrat b1("Alice", 1);
		std::cout << b1 << std::endl;
		std::cout << "Trying to increase grade beyond max (should throw)" << std::endl;
		b1.increaseGrade(); // Should throw GradeTooHighException
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
		std::cout << "OKAY\n";
	}

	try {
		std::cout << "\nCreating Bureaucrat with grade 150 (lowest)" << std::endl;
		Bureaucrat b2("Bob", 150);
		std::cout << b2 << std::endl;
		std::cout << "Trying to decrease grade beyond min (should throw)" << std::endl;
		b2.decreaseGrade(); // Should throw GradeTooLowException
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
		std::cout << "OKAY\n";

	}
		try {
		std::cout << "\nCreating Bureaucrat with Default Constructor" << std::endl;
		Bureaucrat b2;
		std::cout << b2 << std::endl;
		std::cout << "Trying to decrease grade beyond min (should throw)" << std::endl;
		b2.decreaseGrade(); // Should throw GradeTooLowException
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
		std::cout << "OKAY\n";

	}
}

void testCopyAndAssignment() {
	std::cout << "\nTesting copy constructor and assignment operator\n";
	Bureaucrat original("Charlie", 42);
	Bureaucrat copy = original; // copy constructor
	std::cout << "Copy: " << copy << std::endl;

	Bureaucrat assigned("Dummy", 100);
	assigned = original; // assignment operator
	std::cout << "Assigned: " << assigned << std::endl;
}

void testCustomExceptions() {
	try {
		throwError(MyError("Custom MyError thrown"));
	} catch (const MyError &e) {
		std::cout << "\nCaught MyError: " << e.what() << std::endl;
	}

	try {
		throw DataBaseError("Database connection failed", 503);
	} catch (const DataBaseError &e) {
		std::cout << "Caught DataBaseError: " << e.what() << std::endl;
		std::cout << "Error code: " << e.getErrorCode() << std::endl;
	}
}

int main() {
	testBureaucratGrades();
	testCopyAndAssignment();
	testCustomExceptions();

	return 0;
}
