#include <iostream>
#include "string.h"
#include "tree.h"

using namespace std;

void printTree(tree t) {
	if (t == NULL) {
		return;
	}

	print(getInfo(t));
	cout << endl;

	if (getNextSibling(t) == NULL) {
		printTree(getFirstChild(t));
	} else {
		printTree(getNextSibling(t));
	}
}

int main() {
	tree t = newNode("Luca");

	tree c = newNode("Paolo");
	insertChild(t, c);

	c = newNode("Marco");
	insertChild(t, c);
	insertSibling(c, newNode("Lucia"));

	c = newNode("Anna");
	insertChild(t, c);

	printTree(t);

	return 0;
}