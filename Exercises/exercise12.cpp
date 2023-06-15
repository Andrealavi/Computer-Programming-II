#include <iostream>
#include <cmath>

using namespace std;

float recursivePower(float base, float exp) {
	if (base == 1 || exp == 0) {
		return 1;
	} else if (exp == 1) {
		return base;
	}

	return recursivePower(base, floor(exp / 2)) *
		   recursivePower(base, ceil(exp / 2));
}

int main() {
	cout << recursivePower(2, 3) << endl;
	cout << recursivePower(5, 6) << endl;

	return 0;
}