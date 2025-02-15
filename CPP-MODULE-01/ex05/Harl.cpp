#include "Harl.hpp"

void Harl::complain( std::string level ) {

	std::string lvls[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void (Harl::*functions[])() = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};

	for (int i = 0; i < 4; i++) {
		if (level == lvls[i]) {
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "[ Invalid complaint level ]" << std::endl;
}

void Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void Harl::info() {
	std::cout << " cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << " You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
