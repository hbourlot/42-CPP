/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:29:35 by hbourlot          #+#    #+#             */
/*   Updated: 2025/07/27 20:09:03 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream>

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target() {};

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target + "_shruberry") {};

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &object) {
	_target = object._target;
	// AForm::
};

// Operator =
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &object) {

	_target = object._target;
	// AForm::

	return *this;
};

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {};

// Virtual Member
void ShrubberyCreationForm::executeAction() const {

	std::ofstream ofs(_target.c_str());
	if (!ofs)
		return throw ShrubberyCreationFormException("Failed creating file.");
	ofs << "       _-_\n"
	       "    /~~   ~~\\\n"
	       " /~~         ~~\\\n"
	       "{               }\n"
	       " \\  _-     -_  /\n"
	       "   ~  \\\\ //  ~\n"
	       "_- -   | | _- _\n"
	       "  _ -  | |   -_\n"
	       "      // \\\\\n";

	ofs.close();
};

// Getters
const std::string ShrubberyCreationForm::getTarget() const {
	return _target;
}