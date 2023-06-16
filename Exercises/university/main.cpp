#include <iostream>
#include <cstring>
#include <fstream>

#include "type.h"
#include "tree.h"

using namespace std;

infType makeInf(const char* name, assetType type) {
	infType u;

	strcpy(u.name, name);
	u.type = type;

	return u;
}

node* newNode(infType inf) {
	node* n = new node;

	copy(n->inf, inf);
	n->firstChild = n->nextSibling = n->parent = NULL;

	return n;
}

void serialize(tree t) {
	if (t != NULL) {
		cout << "(";
		print(t->inf);

		if (getFirstChild(t) != NULL) {
			serialize(getFirstChild(t));
		}

		cout << ")";

		if (getNextSibling(t) != NULL) {
			serialize(getNextSibling(t));
		}
	}
}

void loadTree(tree& t, ifstream& file) {
	if (file.peek() != EOF) {
		char type, name[51];

		file >> type;

		if (type == '}') {
			return;
		}

		if (type == '{') {
			file >> type;
		}

		if (type == 'U') {
			file >> name;

			if (t == NULL) {
				t = newNode(makeInf(name, University));
			} else {
				t->nextSibling = newNode(makeInf(name, University));
			}
		} else if (type == 'D') {
			file >> name;

			node* n = newNode(makeInf(name, Department));
			loadTree(n, file);

			if (getFirstChild(t) == NULL) {
				insertChild(t, n);
			} else {
				insertSibling(getFirstChild(t), n);
			}
		} else if (type == 'B') {
			file >> name;

			node* n = newNode(makeInf(name, Building));
			loadTree(n, file);

			if (getFirstChild(t) == NULL) {
				insertChild(t, n);
			} else {
				insertSibling(getFirstChild(t), n);
			}
		} else {
			file >> name;

			node* n = newNode(makeInf(name, Room));

			if (getFirstChild(t) == NULL) {
				insertChild(t, n);
			} else {
				insertSibling(getFirstChild(t), n);
			}
		}

		loadTree(t, file);
	}
}

int main() {
	/**
		tree t = newNode(makeInf("UNIMORE", University));

		insertChild(t, newNode(makeInf("FIM", Department)));

		insertChild(getFirstChild(t), newNode(makeInf("Fisica", Building)));
		insertSibling(getFirstChild(getFirstChild(t)),
					  newNode(makeInf("Matematica", Building)));

		tree temp = getFirstChild(getFirstChild(t));

		insertChild(temp, newNode(makeInf("L1.1", Room)));
		insertSibling(getFirstChild(temp), newNode(makeInf("L1.2", Room)));
		insertSibling(getNextSibling(getFirstChild(temp)),
					  newNode(makeInf("L1.3", Room)));

		temp = getNextSibling(temp);

		insertChild(temp, newNode(makeInf("M0.1", Room)));
		insertSibling(getFirstChild(temp), newNode(makeInf("M1.1", Room)));
		insertSibling(getNextSibling(getFirstChild(temp)),
					  newNode(makeInf("M1.2", Room)));

	*/
	tree t = NULL;
	ifstream file("./uniStructure.txt");

	loadTree(t, file);

	serialize(t);

	cout << endl;

	return 0;
}