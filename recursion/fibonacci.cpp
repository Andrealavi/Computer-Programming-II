#include <iostream>

using namespace std;

int fib(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}

	return fib(n - 1) + fib(n - 2);
}

int main() {
	int n;

	cout << "Insert a number: ";
	cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << fib(i) << endl;
	}

	return 0;
}