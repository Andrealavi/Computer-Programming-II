#include <iostream>

using namespace std;

int main() {
	int n;
	char* characters;

	cout << "Insert a number: ";
	cin >> n;
	cout << endl;

	characters = new char[n + 1];

	for (int i = 0; i < n; i++) {
		cout << "Insert a character: ";
		cin >> characters[i];
		cout << endl;
	}

	characters[n] = '\0';

	cout << characters << endl;

	return 0;
}