#include "Serializer.hpp"
#include <iostream>


void debugPrintDataPointer(const std::string &label, Data *ptr) {
	std::cout << label << ": " << ptr
	          << " | Address value: " << ptr->getAddr() << std::endl;
}

void testSerialization() {
	std::cout << "===== Serializer Debug Test =====" << std::endl;

	// Original data
	Data d(123456);
	std::cout << "[Original Data Created]\n";
	debugPrintDataPointer("Original (d)", &d);

	// Serialize
	uintptr_t raw = Serializer::serialize(&d);
	std::cout << "\n[Serialized]\nRaw uintptr_t: " << raw << std::endl;

	// Deserialize
	Data *n = Serializer::deserialize(raw);
	std::cout << "\n[Deserialized Pointer]\n";
	debugPrintDataPointer("Deserialized (n)", n);

	// Modify original
	std::cout << "\n[Modifying Original Data Value...]\n";
	d.setAddr(12344444);

	// Show values again
	std::cout << "\n[After Modification]\n";
	debugPrintDataPointer("Original (d)", &d);
	debugPrintDataPointer("Deserialized (n)", n);

	// Check if they are the same pointer
	std::cout << "\n[Pointer Identity Check] ";
	if (&d == n) {
		std::cout << "✅ Same pointer\n";
	} else {
		std::cout << "❌ Not the same pointer\n";
	}
	std::cout << "=================================\n";
}

int main() {
	testSerialization();
	return 0;
}
