#include <iostream>

using namespace std;

char* circularArrayAccess(int argc, int i, char* arr[]) {
	return *(arr + (i % argc));
}

int main(int argc, char* argv[]) {
	for (int i = 0; i < 10; i++) {
		cout << circularArrayAccess(argc, i, argv) << endl;
	}

	return 0;
}