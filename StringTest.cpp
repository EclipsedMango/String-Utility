#include "StringTest.h"

#include <iostream>
#include <fstream>
#include <iomanip>

#define RED "\033[38;5;196m"
#define GREEN "\033[38;5;46m"
#define BLUE "\033[38;5;51m"
#define WHITE "\033[38;5;255m"

int StringTest::runTests() {
	testSucceeds = 0;
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

	saveToFile();

	return 0;
}

void StringTest::testTemplate(std::string msg, bool condition) {
	std::cout << msg;
	if (condition) {
		testSucceeds += 1;
		std::cout << GREEN << "Passed." << WHITE << "\n";
	} else {
		std::cout << RED << "Failed." << WHITE << "\n";
	}

	strings.push_back(msg);
	boolVector.push_back(condition);
}

void StringTest::saveToFile() {
	std::ofstream MyFile;
	MyFile.open("C:/Users/s242072/source/repos/String Utility/StringUtilityTestResults.txt", std::ofstream::app);

	time_t myTime = time(nullptr);
	std::tm tm = *std::localtime(&myTime);

	float percent = testSucceeds / numberOfTests * 100;

	MyFile << "Date: " << std::put_time(&tm, "%d/%m/%y ") << "Time: " << std::put_time(&tm, "%H:%M:%S ") << 
		"Success Rate: " << std::setprecision(3) << percent << "%" << "\n";

	for (int i = 0; i < 12; ++i) {
		MyFile << "Test " << i << " " << strings[i];

		if (boolVector[i]) {
			MyFile << "Successful\n";
		} else {
			MyFile << "Failed\n";
		}
	}

	MyFile << '\n';
	MyFile.close();

	std::cout << "Wrote to file.\n";
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