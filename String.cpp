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
	if (_other.string == nullptr) {
		return;
	}

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
	if (_str.size < 1) {
		return *this;
	}

	size += _str.size;
	char* newString = new char[size + 1];

	strcpy(newString, string);
	if (string != nullptr) {
		delete[] string;
	}

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

// If the characters exist in the string then replace them.
int String::Replace(const char _find, const char _replace) {
	int replaceCounter = 0;

	for (size_t i = 0; i < size; ++i) {
		if (string[i] == _find) {
			++replaceCounter;
			string[i] = _replace;
		}
	}

	return replaceCounter;
}

// Reads console buffer and makes a new string based off of that.
String& String::ReadFromConsole() {
	// Clear buffer.
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	// Get characters at buffer, get the size of buffer.
	std::cin.rdbuf()->sgetc();
	std::streamsize bufferSize = std::cin.rdbuf()->in_avail();

	// Make a new string based on the characters in the buffer and the buffers size.
	char* newString = new char[bufferSize];
	for (std::streamsize i = 0; i < bufferSize - 1; ++i) {
		newString[i] = std::cin.rdbuf()->sbumpc();
	}
	newString[bufferSize - 1] = '\0';

	// if string is null then make a new string otherwise append.
	if (string == nullptr) {
		string = newString;
		size = bufferSize - 1;
	} else {
		Append(newString);
		delete[] newString;
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

// Goes through each character and compares them then returns false if characters don't match.
bool String::operator==(const String& _other) const {
	if (string == nullptr || _other.string == nullptr) {
		return false;
	}

	for (size_t i = 0; i < _other.size; ++i) {
		if (string[i] != '\0' && _other.string[i] != '\0') {
			if (string[i] == _other.string[i]) {
				return true;
			}
		}
	}

	return false;
}

// Goes through each character and compares them then returns false if characters don't match.
bool String::operator!=(const String& _other) const {
	if (string == nullptr || _other.string == nullptr) {
		return false;
	}

	for (size_t i = 0; i < _other.size; ++i) {
		if (string[i] != '\0' && _other.string[i] != '\0') {
			if (string[i] != _other.string[i]) {
				return false;
			}
		}
	}

	return true;
}

// Finds the character at index, returns Null Terminated if index is too big or small.
char& String::operator[](size_t _index) {
	if (_index > 0 && _index <= size - 1) {
		return string[_index];
	}

	return string[size];
}

// Finds the character at index, returns Null Terminated if index is too big or small.
const char& String::operator[](size_t _index) const {
	if (_index > 0 && _index <= size - 1) {
		return string[_index];
	}

	return string[size];
}

// Set each character to the second string and return.
String& String::operator=(const String& _str) {
	if (string != nullptr) {
		delete[] string;
	}

	if (string == _str.string) {
		return *this;
	}

	string = new char[_str.size + 1];
	size = _str.size;

	for (size_t i = 0; i < _str.size; ++i) {
		string[i] = _str[i];
	}

	string[size] = '\0';
	return *this;
}

// Compare each char to each other in alphabetical order return true if right char is lower.
bool String::operator<(const String& _str) {
	if (string == nullptr || _str.string == nullptr) {
		return false;
	}

	for (size_t i = 0; i < size; ++i) {
		if (string[i] != '\0' && _str[i] != '\0') {
			if (string[i] < _str[i]) {
				return true;
			}
			else {
				return false;
			}
		}
	}

	return false;
}



