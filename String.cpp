#include "String.h"

#include <iostream>
#include <cctype>

// Constructors
String::String() {
	string = nullptr;
	size = 0;
}

String::String(const String& _other) {
	size = _other.size;
	string = new char[size + 1];

	strcpy(string, _other.string);
}

String::String(const char* _str) {
	size = strlen(_str);
	string = new char[size + 1];

	strcpy(string, _str);
}

// Utility Functions
String& String::ToLower() {
	for (size_t i = 0; i < size; ++i) {
		string[i] = tolower(string[i]);
	}

	return *this;
}

String& String::ToUpper() {
	for (size_t i = 0; i < size; ++i) {
		string[i] = toupper(string[i]);
	}

	return *this;
}

String& String::WriteToConsole() {
	for (size_t i = 0; i < strlen(string); ++i) {
		std::cout << string[i];

		if (string[i] == '\0') {
			return *this;
		}
	}
	return *this;
}


