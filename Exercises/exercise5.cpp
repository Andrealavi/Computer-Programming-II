#include <iostream>
#include <cstring>

using namespace std;

void emptyArray(int arr[]) {
	for (int i = 0; i < 32; i++) {
		arr[i] = 0;
	}
}

void extractNumbers(char *input, int num[]) {
	char tempNum[3] = "";
	int count = 0;

	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] != ' ' && input[i] != '-' && input[i] != '\0') {
			tempNum[count] = input[i];
			count++;
		} else {
			tempNum[count] = '\0';
			num[atoi(tempNum)] = 1;
			strcpy(tempNum, "");
			count = 0;
		}
	}

	tempNum[count] = '\0';
	num[atoi(tempNum)] = 1;
	strcpy(tempNum, "");
	count = 0;
}

void switchLed(int &led, int *num, bool offToOn = false) {
	if (!offToOn) {
		for (int i = 0; i < 32; i++) {
			if (num[i] == 1) {
				led = (led | (1 << i));
			}
		}
	} else {
		led = 0;

		for (int i = 0; i < 32; i++) {
			if (num[i] == 1) {
				led = (led | (1 << i));
			}
		}

		led = ~led;
	}
}

int main() {
	int led = 0;
	char input[51];
	int num[32];

	do {
		emptyArray(num);

		cout << "Insert numbers or a special command: ";
		cin.getline(input, 100);
		cout << endl;

		if (strcmp(input, "all") == 0) {
			led = ~0;
		} else if (strcmp(input, "reset") == 0) {
			led = 0;
		} else if (strcmp(input, "-") == 32) {
			extractNumbers(input, num);
			switchLed(led, num, true);
		} else {
			extractNumbers(input, num);
			switchLed(led, num);
		}

		cout << led << endl;
	} while (true);

	return 0;
}