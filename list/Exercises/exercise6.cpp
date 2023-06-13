#include <iostream>
#include <cmath>

using namespace std;

float square(int n) { return n * n; }

float somma(int a, int b, float (*f1)(float), float (*f2)(int)) {
	if (a > 0 && b > 0) {
		return f1(a) + f1(b);
	} else {
		return f2(a) + f2(b);
	}
}

int main() {
	float a, b;

	a = somma(9, 25, sqrt, square);
	b = somma(-5, -25, sqrt, square);

	cout << a << endl;
	cout << b << endl;

	return 0;
}