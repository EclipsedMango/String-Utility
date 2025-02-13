#include "String.h"

#include <iostream>
#include <cctype>

// Constructors

// Create a string with a size and null termination character.
String::String() {
	string = nullptr;
	size = 0;
}

// Copy the string to _other.
String::String(const String& _other) {
	size = _other.size;
	string = new char[size + 1];

	strcpy(string, _other.string);
}

// Copy the characters to _str.
String::String(const char* _str) {
	size = strlen(_str);
	string = new char[size + 1];

	strcpy(string, _str);
}

// Utility Functions

// Find the length then return that length.
size_t String::Length() const {
	return strlen(string);
}

// Check the size of the string, add to it if needed and add the other string.
String& String::Append(const String& _str) {
	if (sizeof(string) > size + _str.size + 1) {
		return *this;
	}

	strcat(string, _str.string);
	size += _str.size;

	return *this;
}

// Iterates through string replacing characters with lower case characters.
String& String::ToLower() {
	for (size_t i = 0; i < size; ++i) {
		string[i] = tolower(string[i]);
	}

	return *this;
}

// Iterates through string replacing characters with upper case characters.
String& String::ToUpper() {
	for (size_t i = 0; i < size; ++i) {
		string[i] = toupper(string[i]);
	}

	return *this;
}

// Iterate through string and check it the char matches anything in string.
int String::FindCharacter(const char _chr) {
	for (size_t i = 0; i < size; ++i) {
		if (string[i] == _chr) {
			return i;
		}
	}

	return -1;
}


int String::Replace(const char _find, const char _replace) {
	for (size_t i = 0; i < size; ++i) {
		if (string[i] == _find) {
			string[i] = _replace;
		}
	}

	return -1;
}

String& String::ReadFromConsole() {
	std::string str;
	std::cin >> str;

	for (size_t i = 0; i < str.size(); ++i) {
		string[i] = str[i];

		if (string[i] == '\0') {
			return *this;
		}
	}

	return *this;
}

// Iterates through characters and writes them to console until null termination character.
String& String::WriteToConsole() {
	for (size_t i = 0; i < strlen(string); ++i) {
		std::cout << string[i];

		if (string[i] == '\0') {
			return *this;
		}
	}
	return *this;
}


