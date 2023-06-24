#include "key.h"
#include "string.h"
#include "bst.h"

#include <iostream>

using namespace std;

void bstDFS(bst t) {
	if (t != NULL) {
		bstDFS(getLeft(t));

		cout << "Key: ";
		printKey(getKey(t));
		cout << endl << "value: ";
		printInf(getValue(t));
		cout << endl;

		bstDFS(getRight(t));
	}
}

void copyEvenKeys(bst &dest, bst &src) {
	if (src != NULL) {
		if (getKey(src) % 2 == 0) {
			bnode *node = bstNewNode(getValue(src), getKey(src));

			bstInsert(dest, node);
			bst_delete(src, src);
		}

		copyEvenKeys(dest, src->left);
		copyEvenKeys(dest, src->right);
	}
}

int main() {
	bst t = NULL;
	bst evenCopy = NULL;

	bstInsert(t, bstNewNode("Luca", 7));
	bstInsert(t, bstNewNode("Paolo", 2));
	bstInsert(t, bstNewNode("Cac", 7));
	bstInsert(t, bstNewNode("Spec", 26));
	bstInsert(t, bstNewNode("lel", 21));
	bstInsert(t, bstNewNode("Stwer", 28));
	bstInsert(t, bstNewNode("zul", 27));

	bstDFS(t);

	cout << endl;

	copyEvenKeys(evenCopy, t);

	bstDFS(t);

	cout << endl;

	bstDFS(evenCopy);

	return 0;
}