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
	std::tm time = *std::localtime(&myTime);

	MyFile << std::put_time(&time, "Date: %d/%m/%y Time: %H:%M:%S ") << 
		"Success Rate: " << std::setprecision(3) << testSucceeds / numberOfTests * 100 << "%" << "\n";

	for (int i = 0; i < 10; ++i) {
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
	String string = "Test";

	if (string.Length() != index) {
		return false;
	}

	return true;
}

bool StringTest::appendTest() {
	String string = "Test";

	string.Append(" Hello");
	if (string != "Test Hello") {
		return false;
	}

	return true;
}

bool StringTest::toLowerTest() {
	String str = "Test";

	str.ToLower();
	if (str != "test") {
		return false;
	}

	return true;
}

bool StringTest::toUpperTest() {
	String string = "Test";

	string.ToUpper();
	if (string != "TEST") {
		return false;
	}

	return true;
}

bool StringTest::findCharacterTest() {
	String string = "Test";

	if (string.FindCharacter('T') != 0) {
		return false;
	}

	if (string.FindCharacter('K') == 1) {
		return false;
	}

	return true;
}

bool StringTest::replaceTest() {
	String string = "Test";

	if (string.Replace('e', '3') != 1) {
		return false;
	}

	return true;
}

bool StringTest::doubleEqualsTest() {
	String string = "Test";

	if (string == "Test") {
		return true;
	}

	return false;
}

bool StringTest::subscriptTest() {
	String string = "Test";

	if (string[0] != 'T') {
		return false;
	}

	return true;
}

bool StringTest::AssignmentTest() {
	String string = "Test";

	string = "test";
	if (string == "test"){
		return true;
	}

	return false;
}

bool StringTest::lessThanTest() {
	String string = "Test";

	if (string < "abce") {
		return true;
	}

	return false;
}