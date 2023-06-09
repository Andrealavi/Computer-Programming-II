#include <iostream>
#include <cstring>

#include "string.h"

using namespace std;

int compare(infType s1, infType s2) { return strcmp(s1, s2); }

void copy(infType &dest, infType src) {
	dest = new char[50];
	strcpy(dest, src);
}

void print(infType s) { cout << s; }