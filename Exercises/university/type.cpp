#include <iostream>
#include <cstring>

#include "type.h"

using namespace std;

int compare(infType u1, infType u2) {
	if (u1.type != u1.type) {
		return u1.type - u2.type;
	} else {
		return strcmp(u1.name, u2.name);
	}
}

void copy(infType &u1, infType u2) {
	strcpy(u1.name, u2.name);

	u1.type = u2.type;
}

void print(infType u) {
	char outChar;
	char outStr[51];

	switch (u.type) {
		case University:
			outChar = 'U';
			break;

		case Department:
			outChar = 'D';
			break;

		case Building:
			outChar = 'B';
			break;

		case Room:
			outChar = 'R';
			break;

		default:
			break;
	}

	cout << outChar << " - " << u.name;
}