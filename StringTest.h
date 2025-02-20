#pragma once
#include <string>
#include <vector>

#include "String.h"

class StringTest {
public:
	int runTests();

private:
	String string = "Test";
	float numberOfTests = 12;
	float testSucceeds = 0;

	std::vector<std::string> strings;
	std::vector<bool> boolVector;

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
