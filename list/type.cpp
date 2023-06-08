#include "type.h"

#include <cstring>
#include <iostream>

using namespace std;

int compare(infType s1, infType s2) { return strcmp(s1, s2); }

void print(infType s) { cout << s; }

void copy(infType &dest, infType src) {
	dest = new char[50];
	strcpy(dest, src);
}
