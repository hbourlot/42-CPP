#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
	private:
		Contact _contacts[8];
		int		_idx;
		void addFirstName();
		void addLastName();
		void addPhoneNumber();
		void addDarkSecret();
		void addNickName();
		
		public:
		PhoneBook(){
			this->_idx = 0;
			printPhonebook();
		};
		~PhoneBook() {
			std::cout << "Exiting..." << std::endl;
		};

		void add();
		void search();
		void printPhonebook();
		void printAllPhoneBookContacts();
		void printContact(int idx);

};

#endif