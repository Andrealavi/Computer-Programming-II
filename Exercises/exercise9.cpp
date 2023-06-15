#include <iostream>
#include <algorithm>

using namespace std;

bool ltIntCustom(int a, int b) {
	if ((a % 2 == 0) && (b % 2 != 0)) {
		return true;
	} else if ((a % 2 != 0) && (b % 2 == 0)) {
		return false;
	}

	return a < b;
}

int main() {
	int len = 10;
	int arr[len] = {26, 34, 3, 44, 89, 35, 67, 18, 7, 43};

	sort(arr, arr + len, ltIntCustom);

	for (int i = 0; i < len; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}