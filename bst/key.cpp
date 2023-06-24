#include "key.h"
#include <iostream>

using namespace std;

int compareKey(keyType k1, keyType k2) { return k1 - k2; }

void copy(keyType &k1, keyType k2) { k1 = k2; }

void printKey(keyType k) { cout << k; }