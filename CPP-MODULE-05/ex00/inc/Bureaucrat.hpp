#pragma once

#include <exception>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

/**
 * @class Bureaucrat
 * @brief Represents a bureaucrat with a name and grade.
 *
 * The grade must be within the range 1 (highest) to 150 (lowest).
 * Provides functionality to increase or decrease the bureaucrat's grade.
 * Throws exceptions if grade constraints are violated.
 */
class Bureaucrat {

  private:
	/** The name of the bureaucrat (constant after construction). */
	const std::string _name;

	/** The grade of the bureaucrat. Valid range: 1 (max) to 150 (min). */
	int _grade;

  public:
	/**
	 * @brief Constructs a Bureaucrat with given name and grade.
	 * @param name The name of the bureaucrat.
	 * @param grade The initial grade of the bureaucrat.
	 * @throws GradeTooHighException if grade < 1.
	 * @throws GradeTooLowException if grade > 150.
	 */
	Bureaucrat(std::string name, int grade);

	/**
	 * @brief Default constructor (initializes with default values).
	 */
	Bureaucrat();

	/**
	 * @brief Destructor.
	 */
	~Bureaucrat();

	/**
	 * @brief Copy constructor.
	 * @param object The Bureaucrat object to copy from.
	 */
	Bureaucrat(const Bureaucrat &object);

	/**
	 * @brief Assignment operator.
	 * @param object The Bureaucrat object to assign from.
	 * @return Reference to this Bureaucrat.
	 */
	Bureaucrat &operator=(const Bureaucrat &object);

	/**
	 * @brief Overloaded insertion operator for printing Bureaucrat info.
	 * @param os Output stream.
	 * @param bureaucrat The Bureaucrat to print.
	 * @return Reference to the output stream.
	 */
	friend std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

	/**
	 * @brief Increases the bureaucrat's grade by 1 (higher rank).
	 * @throws GradeTooHighException if resulting grade would be < 1.
	 */
	void increaseGrade();

	/**
	 * @brief Decreases the bureaucrat's grade by 1 (lower rank).
	 * @throws GradeTooLowException if resulting grade would be > 150.
	 */
	void decreaseGrade();

	/**
	 * @class GradeTooHighException
	 * @brief Exception thrown when grade is set too high (less than 1).
	 */
	class GradeTooHighException : public std::runtime_error {
	  public:
		explicit GradeTooHighException(const std::string &message = "Grade too High.") : std::runtime_error(message) {}
	};

	/**
	 * @class GradeTooLowException
	 * @brief Exception thrown when grade is set too low (greater than 150).
	 */
	class GradeTooLowException : public std::runtime_error {
	  public:
		explicit GradeTooLowException(const std::string &message = "Grade too Low.") : std::runtime_error(message) {}
	};

	/**
	 * @brief Gets the name of the bureaucrat.
	 * @return The bureaucrat's name.
	 */
	const std::string &getName() const;

	/**
	 * @brief Gets the grade of the bureaucrat.
	 * @return The bureaucrat's grade.
	 */
	const int &getGrade() const;
};
