#include <iostream>

using namespace std;

void hanoi(int n, char S, char D, char A) {
	if (n == 1) {
		cout << "Move the disk from " << S << " rod to " << D << " rod" << endl;
		return;
	}

	hanoi(n - 1, S, A, D);
	cout << "Move the disk from " << S << " rod to " << D << " rod" << endl;

	hanoi(n - 1, A, D, S);
}

int main() {
	hanoi(3, 'A', 'C', 'B');

	return 0;
}