#include "StringUtility.h"
#include "String.h"
#include "StringTest.h"

#define GOLD "\033[38;5;220m"
#define WHITE "\033[38;5;255m"

using namespace std;

int main() {
	String text = "Hallo World!";
	String originalText = text;

	text.WriteToConsole();
	std::cout << "\n";

	std::cout << "String length " << text.Length() << "\n";

	originalText.Append(" I Appended this!").WriteToConsole();
	std::cout << "\n";

	text.ToLower().WriteToConsole();
	std::cout << "\n";

	text.ToUpper().WriteToConsole();
	std::cout << "\n";

	std::cout << "Character W is at index: " << originalText.FindCharacter('W') << "\n";
	std::cout << "Character K is at index: " << originalText.FindCharacter('K') << "\n";

	std::cout << text.ToLower().Replace('l', 'j');
	std::cout << "\n";
	text.WriteToConsole();
	std::cout << "\n";

	std::cout << "Type something! \n";
	String newText;
	newText.ReadFromConsole().ToUpper().WriteToConsole();
	std::cout << "\n";

	if (text == newText) {
		std::cout << "Text and what you typed are the same! ";
	} else {
		std::cout << "Text and what you typed are not the same! ";
	}

	std::cout << "\n";

	std::cout << "The 6th letter is " << text[6] << "\n";

	text = newText;
	std::cout << "Text now equals what you typed! ";
	text.WriteToConsole();

	std::cout << "\n";

	if (text < "Abc") {
		std::cout << "Text is not ordered better than Abc!\n";
	} else {
		std::cout << "Text is ordered better than Abc!\n";
	}

	std::cout << "All tests are finished good job!\n";
	std::cout << "\n";

	std::cout << GOLD << "Starting Unit tests." << WHITE << "\n";
	StringTest *stringTest = new StringTest;

	stringTest->runTests();

	return 0;
}
