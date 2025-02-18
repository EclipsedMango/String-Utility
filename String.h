#pragma once

class String {
public:
	// Create a string with a size and null termination character.
	String();

	// Copy the characters to _str.
	String(const char* _str);

	// Copy the string to _other.
	String(const String& _other);
	
	~String() = default;

public:
	// Find the length then return that length.
	size_t Length() const;

	// Check the size of the string, add to it if needed and add the other string.
	String& Append(const String& _str);

	// Iterates through string replacing characters with lower case characters.
	String& ToLower();

	// Iterates through string replacing characters with upper case characters.
	String& ToUpper();

	// Iterate through string and check it the char matches anything in string.
	int FindCharacter(const char _chr);

	// If the characters exist in the string then replace them.
	int Replace(const char _find, const char _replace);

	// Reads console buffer and makes a new string based off of that.
	String& ReadFromConsole();

	// Iterates through characters and writes them to console until null termination character.
	String& WriteToConsole();

	// Goes through each character and compares them then returns false if characters don't match.
	bool operator==(const String& _other) const;
	bool operator!=(const String& _other) const;

	// Finds the character at index, returns Null Terminated if index is too big or small.
	char& operator[](size_t _index);
	const char& operator[](size_t _index) const;

	// Set each character to the second string and return.
	String& operator=(const String& _str);

	// Compare each char to each other in alphabetical order return true if right char is lower.
	bool operator<(const String& _str);

private:
	char* string;
	size_t size;
};
