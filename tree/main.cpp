#include <iostream>
#include <algorithm>
#include "string.h"
#include "tree.h"
#include "coda-bfs.h"

using namespace std;

void serialize(tree t) {
	if (t != NULL) {
		cout << "(" << getInfo(t);

		if (getFirstChild(t) != NULL) {
			cout << " ";
			serialize(getFirstChild(t));
		}

		cout << ")";

		if (getNextSibling(t) != NULL) {
			serialize(getNextSibling(t));
		}
	}
}

int getTreeHeight(tree t) {
	if (t != NULL) {
		return max(1 + getTreeHeight(getFirstChild(t)),
				   getTreeHeight(getNextSibling(t)) - 1);
	}
}

int dimensionBFS(tree t) {
	codaBFS q = newQueue();

	q = enqueue(q, t);

	int dim = 0;

	while (!isEmpty(q)) {
		node* n = dequeue(q);

		dim++;

		if (getNextSibling(n) != NULL) {
			q = enqueue(q, getNextSibling(n));
		}

		if (getFirstChild(n) != NULL) {
			q = enqueue(q, getFirstChild(n));
		}
	}

	return dim;
}

int dimensionDFS(tree t) {
	if (t != NULL) {
		return 1 + dimensionDFS(getFirstChild(t)) +
			   dimensionDFS(getNextSibling(t));
	}
}

int main() {
	tree t = newNode("Luca");

	tree c = newNode("Paolo");
	insertChild(t, c);

	insertSibling(c, newNode("Marco"));
	insertChild(c->nextSibling, newNode("Lucia"));
	insertSibling(c->nextSibling, newNode("Anna"));

	serialize(t);
	cout << endl;

	cout << getTreeHeight(t) << endl;
	cout << dimensionBFS(t) << endl;
	cout << dimensionDFS(t) << endl;

	return 0;
}