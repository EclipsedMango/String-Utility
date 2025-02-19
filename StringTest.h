#pragma once
#include <string>

#include "String.h"

class StringTest {
public:
	int runTests();

private:
	String string = "Test";
	int numberOfTests = 11;

	void testTemplate(std::string msg, bool condition);
	void saveToFile();

	bool lengthTest(int index);
	bool appendTest();

	bool toLowerTest();
	bool toUpperTest();

	bool findCharacterTest();
	bool replaceTest();

	bool readFromConsoleTest();
	bool writeToConsoleTest();

	bool doubleEqualsTest();
	bool subscriptTest();
	bool AssignmentTest();
	bool lessThanTest();
};
