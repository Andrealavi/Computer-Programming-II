#include <iostream>

using namespace std;

int main() {
	char c;
	int offset = 'a' - 'A';

	cout << "Insert a character: ";
	cin >> c;
	cout << endl;

	cout << c << endl;

	c = c ^ offset;

	cout << c << endl;

	return 0;
}