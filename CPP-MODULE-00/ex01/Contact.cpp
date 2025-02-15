#include "Contact.hpp"

// GETTERS
std::string Contact::getFirstName(void) {
	return this->_first_name;
};

std::string Contact::getLastName() {
	return this->_last_name;
};

std::string Contact::getNumber() {
	return this->_number;
};

std::string Contact::getNickName() {
	return this->_nick;
};

std::string Contact::getSecret() {
	return this->_secret;
}

// SETTERS
void Contact::setFirstName(std::string name) {
	this->_first_name = name;
};

void Contact::setLastName(std::string last_name) {
	this->_last_name = last_name;
};

void Contact::setNumber(std::string phoneNumber) {
	this->_number = phoneNumber;
};

void Contact::setNick(std::string nick) {
	this->_nick = nick;
}

void Contact::setSecret(std::string secret) {
	this->_secret = secret;
}
