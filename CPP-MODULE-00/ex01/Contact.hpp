#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
	private:
		std::string _number;
		std::string	_first_name;
		std::string _last_name;
		std::string	_nick;
		std::string _secret;

	public:
		// Constructor / Destructor
		Contact() {};
		~Contact() {};		

		// Getters
		std::string getFirstName();
		std::string getLastName();
		std::string getNumber();
		std::string getNickName();
		std::string getSecret();

		// Setters
		void setFirstName(std::string name);
		void setLastName(std::string name);
		void setNumber(std::string phone_number);
		void setNick(std::string nick);
		void setSecret(std::string secret);
};

#endif
