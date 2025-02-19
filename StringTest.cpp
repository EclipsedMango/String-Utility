#include "StringTest.h"

#include <iostream>

#define RED "\033[38;5;196m"
#define GREEN "\033[38;5;46m"
#define BLUE "\033[38;5;51m"
#define WHITE "\033[38;5;255m"

int StringTest::runTests() {
	testTemplate("Length Test: ", lengthTest(4));
	testTemplate("Append Test: ", appendTest());
	testTemplate("ToLower Test: ", toLowerTest());
	testTemplate("ToUpper Test: ", toUpperTest());
	testTemplate("Find Character Test: ", findCharacterTest());
	testTemplate("Replace Character Test: ", replaceTest());
	testTemplate("Read From Console Test: ", readFromConsoleTest());
	testTemplate("Write To Console Test: ", writeToConsoleTest());
	testTemplate("Equality Operator Test: ", doubleEqualsTest());
	testTemplate("Subscript Operator Test: ", subscriptTest());
	testTemplate("Assignment Operator Test: ", AssignmentTest());
	testTemplate("Less Than Operator Test: ", lessThanTest());

	return 0;
}

void StringTest::testTemplate(std::string msg, bool condition) {
	std::cout << msg;
	if (condition) {
		std::cout << GREEN << "Passed." << WHITE << "\n";
	} else {
		std::cout << RED << "Failed." << WHITE << "\n";
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

bool StringTest::toLowerTest() {
	string.ToLower();
	if (string != "test hello") {
		return false;
	}

	return true;
}

bool StringTest::toUpperTest() {
	string.ToUpper();
	if (string != "TEST HELLO") {
		return false;
	}

	return true;
}

bool StringTest::findCharacterTest() {
	if (string.FindCharacter('T') != 0) {
		return false;
	}

	if (string.FindCharacter('K') == 1) {
		return false;
	}

	return true;
}

bool StringTest::replaceTest() {
	if (string.Replace('L', 'J') != 2) {
		return false;
	}

	return true;
}

bool StringTest::readFromConsoleTest(){
	std::cout << "Type test.\n";
	string.ReadFromConsole();
	if (string != "TEST HEJJOtest") {
		return false;
	}

	return true;
}

bool StringTest::writeToConsoleTest() {
	std::cout << BLUE;
	if (string.WriteToConsole() != "TEST HEJJOtest") {
		std::cout << WHITE;
		return false;
	}

	std::cout << WHITE;
	std::cout << "\n";
	return true;
}

bool StringTest::doubleEqualsTest() {
	if (string != "TEST HEJJOtest") {
		return false;
	}

	return true;
}

bool StringTest::subscriptTest() {
	if (string[3] != 'T') {
		return false;
	}

	return true;
}

bool StringTest::AssignmentTest() {
	string = "test";
	if (string == "test"){
		return true;
	}

	return false;
}

bool StringTest::lessThanTest() {
	if (string < "abce") {
		return false;
	}

	return true;
}