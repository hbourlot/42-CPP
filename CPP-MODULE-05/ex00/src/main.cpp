#include "Bureaucrat.hpp"
#include <exception>
#include <stdexcept>

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

void throwError(MyError e) {
	throw e;
}

int main() {

	try {
		Bureaucrat me("Hugo", 149);

		std::cout << me;

		me.decreaseGrade();
		me.decreaseGrade();
		std::cout << me;

	} catch (std::exception &e) {
		std::cout << "Caught error: " << e.what() << std::endl;
	}

	// throwError("MyError e");
	// throwError(MyError("My error"));
	// int a = 40;
	// try {
	// 	throw DataBaseError("Laele", 2);
	// } catch (const DataBaseError &e) {
	// 	std::cout << e.what() << std::endl;
	// 	std::cout << e.getErrorCode() << std::endl;
	// }

	return 0;
}