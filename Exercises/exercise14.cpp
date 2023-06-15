#include <iostream>
#include <cstring>

using namespace std;

void printStringReverse(const char* str) {
	if (*(str) == '\0') {
		return;
	}

	printStringReverse(str + 1);
	cout << *(str);
}

int main() {
	char input[] = "Hello World!";

	cout << input << endl;

	printStringReverse(input);

	cout << endl;

	return 0;
}