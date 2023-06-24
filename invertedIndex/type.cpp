#include "type.h"
#include <iostream>

using namespace std;

int compare(infType s1, infType s2) { return s1 - s2; }

void copy(infType& dest, infType src) { dest = src; }

void printInf(infType s) { cout << s; }