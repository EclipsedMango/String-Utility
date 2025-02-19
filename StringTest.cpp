#include "StringTest.h"

#include <iostream>

int StringTest::runTests() {
	testTemplate("Length Test: ", lengthTest(4));
	testTemplate("Append Test: ", appendTest());
	testTemplate("ToLower Test: ", toLowerTest());
	testTemplate("ToUpper Test: ", toUpperTest());
	testTemplate("Find Character Test: ", findCharacterTest());
	testTemplate("Replace Character Test: ", replaceTest());
	testTemplate("Read From Console Test: ", readFromConsoleTest());
	testTemplate("Write To Console Test: ", writeToConsoleTest());

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
	if (string.WriteToConsole() != "TEST HEJJOtest") {
		return false;
	}

	std::cout << "\n";
	return true;
}

