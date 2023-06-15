#include <iostream>
#include <cmath>

using namespace std;

float square(float n) { return n * n; }

float floatSum(float a, float b, float (*f1)(float), float (*f2)(float)) {
	return f2(f1(a) + f1(b));
}

int main() {
	float result = floatSum(42, 42, square, sqrt);

	cout << result << endl;

	return 0;
}