// String Utility.cpp : Defines the entry point for the application.
//

#include "StringUtility.h"

#include <iso646.h>

#include "String.h"

using namespace std;

int main() {
	String text = "Hallo World!";
	String originalText = text;

	std::cout << "String length " << text.Length() << "\n";

	text.WriteToConsole();
	std::cout << "\n";

	text.ToLower().WriteToConsole();
	std::cout << "\n";

	text.ToUpper().WriteToConsole();
	std::cout << "\n";

	originalText.Append(" I Appended this!").WriteToConsole();
	std::cout << "\n";

	std::cout << "Character W is at index: " << originalText.FindCharacter('W') << "\n";
	std::cout << "Character K is at index: " << originalText.FindCharacter('K') << "\n";

	text.ToLower().Replace('l', 'j');
	text.WriteToConsole();
	std::cout << "\n";

	std::cout << "Type something! \n";
	String newText;
	newText.ReadFromConsole().ToUpper().WriteToConsole();

	return 0;
}
