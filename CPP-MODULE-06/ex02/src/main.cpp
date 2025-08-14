#include "../inc/Base.hpp"
#include <iostream>

// Test generation and pointer identification
void testPointerIdentification() {
    std::cout << "=== Test: Pointer Identification ===" << std::endl;
    Base *ptr = Base::generate();
    if (!ptr) {
        std::cout << "Failed to generate Base-derived object." << std::endl;
        return;
    }
    std::cout << "Generated Base pointer: " << ptr << std::endl;
    Base::identify(ptr);
    std::cout << std::endl;
    delete ptr;
}

// Test generation and reference identification
void testReferenceIdentification() {
    std::cout << "=== Test: Reference Identification ===" << std::endl;
    Base *ptr = Base::generate();
    if (!ptr) {
        std::cout << "Failed to generate Base-derived object." << std::endl;
        return;
    }
    Base &ref = *ptr;
    std::cout << "Generated Base reference: " << &ref << std::endl;
    Base::identify(ref);
    std::cout << std::endl;
    delete ptr;
}

// Test multiple generations to check randomness
void testMultipleGenerations(int count = 5) {
    std::cout << "=== Test: Multiple Generations ===" << std::endl;
    for (int i = 0; i < count; ++i) {
        Base *ptr = Base::generate();
        std::cout << "Run " << i+1 << ": Generated pointer " << ptr << " => ";
        Base::identify(ptr);
        delete ptr;
    }
    std::cout << std::endl;
}

int main() {
    testPointerIdentification();
    testReferenceIdentification();
    testMultipleGenerations(10);
    return 0;
}
