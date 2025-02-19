#include "StringTest.h"

#include <iostream>

int StringTest::runTests() {
	testTemplate("Length Test: ", lengthTest(4));
	testTemplate("Append Test: ", appendTest());

	return 0;
}

void StringTest::testTemplate(std::string msg, bool condition) {
	std::cout << msg;
	if (condition) {
		std::cout << "Passed.\n";
	} else {
		std::cout << "Failed.\n";
	}
}

bool StringTest::lengthTest(int index) {
	if (string.Length() != index) {
		return false;
	}

	return true;
}

bool StringTest::appendTest() {
	string.Append("Hello");
	if (string != "Test Hello") {
		return false;
	}

	return true;
}