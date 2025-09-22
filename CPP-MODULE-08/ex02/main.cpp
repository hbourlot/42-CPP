
#include "MutantStack.hpp"

// Basic push & top test
void testBasicPushTop() {
	std::cout << "== Basic push & top ==" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << std::endl;
}

// Pop and size test
void testPopAndSize(MutantStack<int> &mstack) {
	std::cout << "\n== Pop and size ==" << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
}

// Push more elements and print size
void testPushMore(MutantStack<int> &mstack) {
	std::cout << "\n== Push more elements ==" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Size after pushes: " << mstack.size() << std::endl;
}

// Iterate and print all elements
void testIteration(MutantStack<int> &mstack) {
	std::cout << "\n== Iterate from begin to end ==" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// Large test: push many numbers and check size + some elements
void testLargePush(MutantStack<int> &mstack) {
	std::cout << "\n== Large test: push 10,000 numbers ==" << std::endl;
	for (int i = 0; i < 10000; ++i)
		mstack.push(i);

	std::cout << "Size after large push: " << mstack.size() << std::endl;

	std::cout << "First 5 elements: ";
	MutantStack<int>::iterator it = mstack.begin();
	for (int i = 0; i < 5 && it != mstack.end(); ++i, ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Last 5 elements: ";
	it = mstack.end();
	for (int i = 0; i < 5; ++i)
		--it;
	for (int i = 0; i < 5; ++i, ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// Exception test: pop all and then pop once more to trigger exception
void testPopException() {
	std::cout << "\n== Exception test: pop all and pop one more ==" << std::endl;
	MutantStack<int> mstack;
	// Fill with some elements first
	for (int i = 0; i < 10; ++i)
		mstack.push(i);

	try {
		while (!mstack.empty()) {
			mstack.pop();
		}
		std::cout << "Stack emptied. Attempting one more pop..." << std::endl;
		mstack.pop(); // should throw if implemented
	} catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

int main() {
	testBasicPushTop();

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	testPopAndSize(mstack);
	testPushMore(mstack);
	testIteration(mstack);
	testLargePush(mstack);
	testPopException();

	return 0;
}
