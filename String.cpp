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
	if (string == nullptr || _str.size < 1) {
		return *this;
	}

	size += _str.size;
	char* newString = new char[size + 1];

	strcpy(newString, string);
	delete[] string;

	strcat(newString, _str.string);
	string = newString;
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
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.rdbuf()->sgetc();
	std::streamsize bufferSize = std::cin.rdbuf()->in_avail();

	char* newString = new char[bufferSize];
	for (std::streamsize i = 0; i < bufferSize - 1; ++i) {
		newString[i] = std::cin.rdbuf()->sbumpc();
	}
	newString[bufferSize - 1] = '\0';

	if (string == nullptr) {
		string = newString;
		size = bufferSize - 1;
	} else {
		Append(newString);
	}

	return *this;
}

// Iterates through characters and writes them to console until null termination character.
String& String::WriteToConsole() {
	if (string == nullptr) {
		return *this;
	}

	std::cout << string;
	return *this;
}

bool String::operator==(const String& _other) {
	if (string == nullptr) {
		return false;
	}

	for (size_t i = 0; i < size + _other.size; ++i) {
		if (string[i] != _other.string[i]) {
			return false;
		}
	}

	return true;
}

char& String::operator[](size_t _index) {
	if (_index > 0 && _index < size - 1) {
		return string[_index];
	}

	return string[_index];
}

const char& String::operator[](size_t _index) const {
	if (_index > 0 && _index < size - 1) {
		return string[_index];
	}

	return string[_index];
}

String& String::operator=(const String& _str) {
	char* newString = new char[_str.size];
	strcpy(newString, string);
	delete string;

	for (size_t i = 0; i < _str.size; ++i) {
		newString[i] = _str[i];
	}

	string = newString;
	return *this;
}


bool String::operator<(const String& _str) {
	for (size_t i = 0; i < size; ++i) {
		if (string[i] < _str[i]) {
			return true;
		}
		else {
			return false;
		}
	}

	return false;
}



