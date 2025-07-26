#include "PhoneBook.hpp"

static void printParameter(std::string source) {
	int max;
	
	if (source.length() > 10)
	{
		max = 0;
		while (max < 9) {
			std::cout << source[max];
			max++;
		}
		std::cout << ".";
		return;
	}
	max = 0;
	while (source.length() + max < 10) {
		std::cout << " ";
		max++;
	}
	std::cout << source;
}

void PhoneBook::printAllPhoneBookContacts() {
	if (this->_idx > 0) {
		std::string src;
		for (int i = 0; i < _idx; i++) {
			std::cout << " |         " << i + 1 << "|";
			printParameter(_contacts[i].getFirstName());
			std::cout << "|";
			printParameter(_contacts[i].getLastName());
			std::cout << "|";
			printParameter(_contacts[i].getNickName());
			std::cout << "|";
			printParameter(_contacts[i].getNumber());
			std::cout << "|\n";
		}
	}
}

void PhoneBook::printPhonebook() {
	std::cout << "  ______________________________________________________\n";
	std::cout << " |                        PHONE BOOK                    |\n";
	std::cout << " |------------------------------------------------------|\n";
	std::cout << " |       Idx|First Name| Last Name| Nick Name|    Number|\n";
	std::cout << " |------------------------------------------------------|\n";
	printAllPhoneBookContacts();
	std::cout << " |------------------------------------------------------|\n";
	std::cout << " | Commands:    ADD            SEARCH           EXIT    |\n";
	std::cout << " |______________________________________________________|\n";
}

static std::string grepAnswer(const char *question) {
    std::string answer;
	
	while (!std::cin.eof())
	{	
		std::cout << question;
		if (std::getline(std::cin, answer) && answer != "")
			return answer;
		if (std::cin.eof())
			std::exit(0);
	}
    return answer;
}

void PhoneBook::addFirstName() {
    
	std::string first_name = grepAnswer("First name: ");
    this->_contacts[this->_idx].setFirstName(first_name);
}
void PhoneBook::addLastName() {

	std::string last_name = grepAnswer("Last name: ");
	this->_contacts[this->_idx].setLastName(last_name);
}

void PhoneBook::addPhoneNumber() {

	std::string phone_number = grepAnswer("Phone number: ");
	this->_contacts[this->_idx].setNumber(phone_number);
}

void PhoneBook::addDarkSecret() {

	std::string secret = grepAnswer("What's your darkest secret: ");
	this->_contacts[this->_idx].setSecret(secret);
}

void PhoneBook::addNickName() {

	std::string nick_name = grepAnswer("Nick name: ");
	this->_contacts[this->_idx].setNick(nick_name);
}

void PhoneBook::add() {

	if (this->_idx > 7) {
		std::cout << "I'll overwrite last contact now!\n";
		this->_idx = 7;
	}
	addFirstName();
	addLastName();
	addNickName();
	addPhoneNumber();
	addDarkSecret();
	this->_idx += 1;
}

void PhoneBook::printContact(int idx) {

	std::cout << "First name: " << this->_contacts[idx].getFirstName() << std::endl;
	std::cout << "Last name: " << this->_contacts[idx].getLastName() << std::endl;
	std::cout << "Nick name: " << this->_contacts[idx].getNickName() << std::endl;
	std::cout << "Phone number: " << this->_contacts[idx].getNumber() << std::endl;
	std::cout << "Darkest secret: " << this->_contacts[idx].getSecret() << std::endl;

}

void PhoneBook::search() {
	
	std::string answer;
	int			index, i;

	if (this->_idx == 0) {
		std::cout << "PhoneBook is empty!\n";
		return ;
	}

	while (!std::cin.eof()) {

		std::cout << "Which idx: ";
		if (!std::getline(std::cin, answer) && answer == "")
			continue;
		if (std::cin.eof())
			std::exit(0);

		try {
			i = 0;
			while (answer[i]) {
				if (!std::isdigit(answer[i]))
					throw std::exception();
				i++;
			}
			index = std::atoi(answer.c_str()) -1;
			if (index >= 0 && index < this->_idx && index >= 0 && index <= 8)
				return printContact(index);
		} catch (const std::exception&) {
			std::cout << "Type only digits!\n";
			continue;
		}
		std::cout << "Select a valid index!\n";

	}
}
